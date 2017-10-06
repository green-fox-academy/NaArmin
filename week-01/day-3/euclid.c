#include <stdio.h>
#include <stdlib.h>

/*
find the greatest common divisor of the two given variables
use Euclid's algorithm, if you don't know it look it up on the internet
*/

int main()
{
    int x = 32;
    int y = 20;

    int tmp;

    if (x < y) {
        tmp = x;
        x = y;
        y = tmp;
    }
    while (y != 0) {
        tmp = x % y;
        x = y;
        y = tmp;
    }
    printf("The GCD of x and y is %d\n", x);
    return 0;
}
