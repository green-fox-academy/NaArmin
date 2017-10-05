#include <stdio.h>
#include <stdlib.h>

/*
create a program which generates numbers from 0 to 100
for each number write if the number is odd or even (don't print out the numbers)
*/

int main()
{
    int i = 0;
    int s;
    while (i <= 100) {
        s = i % 2;
        switch (s) {
        case 0 :
            printf("Num is even.\n");
            break;
        case 1 :
            printf("Num is odd.\n");
            break;
        }
    i++;
    }
    return 0;
}
