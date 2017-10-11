#include <stdio.h>
#include <limits.h>

int main()
{
	int number_array[8] = {48, 59, 2, -8, 55, 56, 78, 12};

	//TODO:
	// Write a C program to find the two largest element in an array using only 1 for loop
	// From <limits.h> use INT_MIN: this is the least integer
	int biggest1;
	int biggest2;
	int tmp1 = INT_MIN;
	int tmp2 = INT_MIN;
	for (int i = 0; i < sizeof(number_array) / sizeof(number_array[0]); i++) {
        if (number_array[i] > tmp1) {
            biggest1 = i;
            tmp1 = number_array[i];
        }
        i++;
        if (number_array[i] > tmp2) {
            biggest2 = i;
            tmp2 = number_array[i];
        }
	}
    printf("The greatest 2 elements: %d, %d\n", number_array[biggest1], number_array[biggest2]);
	return 0;
}

