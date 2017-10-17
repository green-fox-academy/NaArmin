#include <stdio.h>
#include <string.h>

//TODO: write a function which returns 485 as unsigned integer value
//put your return value in an integer variable in which you should have 229, and print it out
//try to figure out which type casting you should use
unsigned int ret_485(void);

int main()
{
    int number = (unsigned char) ret_485();

	printf("%d", number);
    return 0;
}
unsigned int ret_485(void)
{
    return 485;
}

