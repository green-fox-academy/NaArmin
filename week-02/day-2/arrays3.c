#include <stdio.h>

int main() {
    int int_array[] = {1, 654, 987, 654, 31,};
    float float_array[] = {1.2, 3.14, 1.41, 0.707, 1.73};

    int s = sizeof(int_array) / sizeof(int_array[0]);
	//TODO:
    // Print out the content of the arrays
    for (int i = 0; i < s; i++)
        printf("The %2d.  int element is %d\n", i + 1, int_array[i]);
    puts("");
    s = sizeof(float_array) / sizeof(float_array[0]);
    for (int j = 0; j < s; j++)
        printf("The %2d. float element is %.4f\n", j + 1, float_array[j]);
    return 0;
}

