#include <stdio.h>
#include <stdlib.h>

double arr_sum_avg(int*, int*);

int main()
{
    int* first_array = {10, 20, 30, 40, 50, 60};
    int* second_array = {2, 4, 8, 16};

    arr_sum_avg(first_array, second_array);
    printf("Sum of the 2 arrays' average:\n");
    return 0;
}
double arr_sum_avg(int* arr_in1, int* arr_in2)
{
    double avg = 0;
    long sum = 0;
    for (int i = 0; i < sizeof(arr_in1) - 1; ++i) {
        sum += arr_in1[i];
    }
    printf("%d", i);
}
