#include <stdio.h>
#include <stdlib.h>

// create a function which returns the power of a base number

int powered(int, int);
int main()
{
    int base = 2;
    int power = 7;

    printf("%d\n", powered(base, power));
    return 0;
}
int powered(int basenum, int power)
{
    if (power == 0)
        return 1;
    int val = basenum;
    while (power > 1) {
        val *= basenum;
        power--;
    }
    return val;
}
