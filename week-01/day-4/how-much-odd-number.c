#include <stdio.h>
#include <stdlib.h>

//how much odd numbers are between 179 & 371
//you should be able to change the limits, like from 10 to 234
//and the program should print out the odd numbers between those two numbers
//example from 11 to 27 the program should print out:
// 13, 15, 17, 19, 21, 23, 25 this is 7 odd number between 11 and 27

int main()
{
    int limit_l = 179;
    int limit_u = 371;
    int c = 0;

    for (int i = limit_l + 1; i < limit_u; i++) {
        printf((i % 2 == 1) ? "%d\t" :"", i);
        c++;
    }
    printf("\n\nthere are %d odd numbers between %d and %d", c, limit_l, limit_u);
	return 0;
}
