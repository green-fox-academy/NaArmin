#include <stdio.h>
#include <stdlib.h>

/*
create a simple program which checks if the num is odd or even
*/

int main()
{
    int num;
    num = 13;
    int s = num % 2;
switch (s) {
case 0 :
    printf("Num is even.");
    break;
case 1 :
    printf("Num is odd.");
    break;
default :
    printf("Num is incorrect.");
}
    return 0;
}
