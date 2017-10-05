#include <stdio.h>
#include <stdlib.h>

/*
write a program that decides which number is bigger
use switch-statement
*/

int main()
{
    int num1;
    int num2;

    num1 = 96;
    num2 = 96;
    num1 -= num2;

    switch (num1 < 0) {
    case 1 :
        printf("Num1 is smaller.\n");
        break;
    case 0 :
        printf("Num1 is bigger.\n");
    }
    return 0;
}
