#include <stdio.h>
#include <stdlib.h>

double arr_sum_avg(int*, int*);

int main()
{
    int first_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int second_array[] = {2, 4, 8, 16};

    printf("Sum of the 2 arrays' average: %g\n", arr_sum_avg(first_array, second_array));
    return 0;
}
double arr_sum_avg(int* arr_in1, int* arr_in2)
{
    double avg = 0;
    long sum = 0;
    int i;
    for (i = 0; i < (sizeof(arr_in1)); i++) {
        sum += arr_in1[i]; printf(" %d ", i);
    }
    for (i = 0; i < sizeof(arr_in2); i++) {
        avg += arr_in2[i]; printf(" %d ", i);
    }
    avg += sum;
    avg /= 2;
    return avg;
}
