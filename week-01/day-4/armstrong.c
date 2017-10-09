#include <stdio.h>
/*
 An Armstrong number is an n-digit number that is equal to the sum of the nth powers of its digits.
*/
int main()
{
    int number = 91;
    int sum = 0;
    int digits = 1;
    int tmp = number;
    int n;

    while (tmp >= 10) {
        digits++;
        tmp /= 10;
    }
    if (digits == 1)
        tmp = number;
    for (int i = digits; i > 0; i--){
        tmp = number / (i * 10);
        n = tmp;
        if (digits == 2)
            tmp *= tmp;
        for (int j = 3; j <= digits; j++)
            tmp *= n;
    }
    sum += tmp;
    printf("%d\n", sum);
    return 0;
}

