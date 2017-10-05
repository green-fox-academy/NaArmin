#include <stdio.h>
#include <stdlib.h>

/*
write a simple program which can help you decide is it hot enough to turn on the AC or not
for example if temperature 20 or less the output is :
it is too cold for the AC
or, the temperature is between 21-24:
it is up to you to turn on the AC
...
*/

int main()
{
    int temperature;
    temperature = 23;

    switch (temperature) {
    case 21 :
    case 22 :
    case 23 :
    case 24 :
        printf("it is up to you to turn on the A/C");
        break;
    case 25 :
    case 26 :
    case 27 :
    case 28 :
    case 29 :
    case 30 :
    case 31 :
    case 32 :
    case 33 :
    case 34 :
    case 35 :
    case 36 :
    case 37 :
    case 38 :
    case 39 :
    case 40 :
    case 41 :
        printf("recommended to turn on A/C");
        break;
    default :
        printf("it is too cold for the A/C");
    }
    return 0;
}
