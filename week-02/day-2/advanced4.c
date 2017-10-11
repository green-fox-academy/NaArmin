#include <stdio.h>
int main()
{
    //write a program which loads up fully a 50-sized integer array starting from 200 in descending order
    //but your array should contain elements which are divisible by 5 and 17
    //print out the array

    int my_array[50];
    int num = 200;
    int i = 0;

    while (i < 50) {
        if (!(num % 17 || num % 5)) {
            my_array[i] = num;
            printf("%d\t", my_array[i]);
            i++;
        }
        num--;
    }
    return 0;
}
