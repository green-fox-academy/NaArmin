/**
  ******************************************************************************
  * @file    USB_Host/HID_RTOS/Src/main.c
  * @author  MCD Application Team
  * @brief   USB host HID Mouse and Keyboard demo main file
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics International N.V. 
  * All rights reserved.</center></h2>
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
USBH_HandleTypeDef hUSBHost;
HID_ApplicationTypeDef Appli_state = APPLICATION_IDLE;
osMessageQId AppliEvent;

/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void Error_Handler(void);
static void CPU_CACHE_Enable(void);
static void USBH_UserProcess(USBH_HandleTypeDef *phost, uint8_t id);
static void HID_InitApplication(void);
static void StartThread(void const *argument);

/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  /* Enable the CPU Cache */
  CPU_CACHE_Enable();
  
  /* STM32F7xx HAL library initialization:
       - Configure the Flash ART accelerator on ITCM interface
       - Configure the Systick to generate an interrupt each 1 msec
       - Set NVIC Group Priority to 4
       - Low Level Initialization
     */
  HAL_Init();
  
  /* Configure the System clock to have a frequency of 200 Mhz */
  SystemClock_Config();
  
  /* Start task */
  osThreadDef(USER_Thread, StartThread, osPriorityNormal, 0, 8 * configMINIMAL_STACK_SIZE);
  osThreadCreate(osThread(USER_Thread), NULL);
  
  /* Create Application Queue */
  osMessageQDef(osqueue, 1, uint16_t);
  AppliEvent = osMessageCreate(osMessageQ(osqueue), NULL);
  
  /* Start scheduler */
  osKernelStart();
  
  /* We should never get here as control is now taken by the scheduler */
  for( ;; );
}

/**
  * @brief  Start task
  * @param  pvParameters not used
  * @retval None
  */
static void StartThread(void const * argument)
{
  osEvent event;
  
  /* Init HID Application */
  HID_InitApplication();
  
  /* Start Host Library */
  USBH_Init(&hUSBHost, USBH_UserProcess, 0);
  
  /* Add Supported Class */
  USBH_RegisterClass(&hUSBHost, USBH_HID_CLASS);
  
  /* Start Host Process */
  USBH_Start(&hUSBHost);
  
  for( ;; )
  {
    event = osMessageGet( AppliEvent, osWaitForever );
    
    if( event.status == osEventMessage )
    {
      switch(event.value.v)
      {
      case APPLICATION_DISCONNECT:
        Appli_state = APPLICATION_DISCONNECT; 
        HID_UpdateMenu();
        break;
        
      case APPLICATION_READY:
        Appli_state = APPLICATION_READY;
        
      default:
        break;
      }
    }
  } 
}

/**
  * @brief  User Process
  * @param  phost: Host Handle
  * @param  id: Host Library user message ID
  * @retval None
  */
static void USBH_UserProcess(USBH_HandleTypeDef *phost, uint8_t id)
{  
  switch(id)
  { 
  case HOST_USER_SELECT_CONFIGURATION:
    break;
    
  case HOST_USER_DISCONNECTION:
    osMessagePut(AppliEvent, APPLICATION_DISCONNECT, 0);
    break;
    
  case HOST_USER_CLASS_ACTIVE:
    osMessagePut(AppliEvent, APPLICATION_READY, 0);
    break;
    
  case HOST_USER_CONNECTION:
    osMessagePut(AppliEvent, APPLICATION_START, 0);
    break;
        
  default:
    break; 
  }
}

/**
  * @brief  HID application Init.
  * @param  None
  * @retval None
  */
static void HID_InitApplication(void)
{
  /* Configure Key Button */
  BSP_PB_Init(BUTTON_TAMPER, BUTTON_MODE_EXTI);
  
  /* Configure LED1*/
  BSP_LED_Init(LED1);
  
  /* Initialize the LCD */
  BSP_LCD_Init();
  
  /* LCD Layer Initialization */
  BSP_LCD_LayerDefaultInit(1, LCD_FB_START_ADDRESS); 
  
  /* Select the LCD Layer */
  BSP_LCD_SelectLayer(1);
  
  /* Enable the display */
  BSP_LCD_DisplayOn();
  
  /* Initialize the LCD Log module */
  LCD_LOG_Init();
  
#ifdef USE_USB_HS 
  LCD_LOG_SetHeader((uint8_t *)" USB OTG HS HID Host");
#else
  LCD_LOG_SetHeader((uint8_t *)" USB OTG FS HID Host");
#endif
  
  LCD_UsrLog("USB Host library started.\n"); 
  
  /* Start HID Interface */
  USBH_UsrLog("Starting HID Demo");
  HID_MenuInit();
}

/**
  * @brief  Toggles LEDs to show user input state.
  * @param  None
  * @retval None
  */
void Toggle_Leds(void)
{
  static uint32_t ticks;

  if(ticks++ == 100)
  {
    BSP_LED_Toggle(LED1);
    ticks = 0;
  }
}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow :
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 200000000
  *            HCLK(Hz)                       = 200000000
  *            AHB Prescaler                  = 1
  *            APB1 Prescaler                 = 4
  *            APB2 Prescaler                 = 2
  *            HSE Frequency(Hz)              = 25000000
  *            PLL_M                          = 25
  *            PLL_N                          = 400
  *            PLL_P                          = 2
  *            PLLSAI_N                       = 384
  *            PLLSAI_P                       = 8
  *            VDD(V)                         = 3.3
  *            Main regulator output voltage  = Scale1 mode
  *            Flash Latency(WS)              = 7
  * @param  None
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct;
  
  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 25;
  RCC_OscInitStruct.PLL.PLLN = 400;  
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 8;
  if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  
  /* Activate the OverDrive to reach the 200 Mhz Frequency */
  if(HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }
  
  /* Select PLLSAI output as USB clock source */
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_CLK48;
  PeriphClkInitStruct.Clk48ClockSelection = RCC_CLK48SOURCE_PLLSAIP;
  PeriphClkInitStruct.PLLSAI.PLLSAIN = 192;
  PeriphClkInitStruct.PLLSAI.PLLSAIQ = 4; 
  PeriphClkInitStruct.PLLSAI.PLLSAIP = RCC_PLLSAIP_DIV4;

  if(HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct)  != HAL_OK)
  {
    Error_Handler();
  }
  
  /* Select PLL as system clock source and configure the HCLK, PCLK1 and PCLK2 
     clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK |
                                 RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2);
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_6) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
static void Error_Handler(void)
{
  /* User may add here some code to deal with this error */
  while(1)
  {
  }
}

/**
  * @brief  CPU L1-Cache enable.
  * @param  None
  * @retval None
  */
static void CPU_CACHE_Enable(void)
{
  /* Enable I-Cache */
  SCB_EnableICache();

  /* Enable D-Cache */
  SCB_EnableDCache();
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/