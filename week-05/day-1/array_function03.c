#include <stdio.h>
#include <string.h>

int *arr_str_len(char **str_arr, int strings);

int main(void)
{
    char *stringarr[] = {"Good", "Morning", "Vietnam"};
    int *chars;
    chars = arr_str_len(stringarr, 3);

    printf("{%d, %d, %d}", chars[0], chars[1], chars[2]);
    return 0;
}
int *arr_str_len(char **str_arr, int strings)
{
    static int lenghts[3];
    for (int i = 0; i < strings; i++)
        lenghts[i] = strlen(str_arr[i]);
    return lenghts;
}

