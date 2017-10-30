#include <stdio.h>

int assort_odd_elements(int *array, int size);

int main(void)
{
	int num_array[] = {8, 7, 9, 20, 3, 81, 79, 66};

    //TODO: write a function which filters out the odd elements of an integer array
    //do it in the original array
    //your return value should be the real size of the filtered array
    //print out the filtered array's elements
    int newsize = assort_odd_elements(&num_array, sizeof(num_array) / sizeof(int));
    printf("The array has %d elements, these are: ", newsize);
    for (int i = 0; i < newsize; i++) {
        printf("%d  ", num_array[i]);
    }

    return 0;
}
int assort_odd_elements(int *array, int size)
{
    int odds_size = size;
    for (int i = 0; i < odds_size; i++) {
        if(array[i] % 2 == 0) {
            odds_size--;
            for (int j = i; j < odds_size - 1; j++)
                array[j] = array[j + 1];
        }

    }
    return odds_size - 1;
}

