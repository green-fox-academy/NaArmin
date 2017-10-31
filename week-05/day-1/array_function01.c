#include <stdio.h>
#include <stdlib.h>

int *mybubblesort(int arr[], unsigned int size);
int mysearch_val(int arr[], unsigned int size, int num_to_s);

int main(void)
{
    int randnums[50];
    int *sorted_a;
    int lookfor;
    int index;
    for (int i = 0; i < 50; i++)
        randnums[i] = rand() % 1000;

    lookfor = randnums[rand() % 50];
    printf("\nLooking for: %d\n", lookfor);
    sorted_a = mybubblesort(randnums, sizeof(randnums) / sizeof(randnums[0]));
    index = mysearch_val(sorted_a, 50, lookfor);
    printf("\nFound at index: %d\n", index);

    lookfor = 1111;
    printf("\nLooking for: %d\n", lookfor);
    index = mysearch_val(sorted_a, 50, lookfor);
    if (index != -1)
        printf("\nFound at index: %d\n", index);
    else
        printf("\n%d not found!", lookfor);
    return 0;
}
int *mybubblesort(int arr[], unsigned int size)
{
    static int sort_arr[50];
    int tmpnum;
    for (int i = 0; i < size - 1; i++)
        sort_arr[i] = arr[i];
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - 1; j++) {

            if (sort_arr[j] > sort_arr[j + 1]) {
                tmpnum = sort_arr[j];
                sort_arr[j] = sort_arr[j + 1];
                sort_arr[j + 1] = tmpnum;
            }
        }
    }
    return sort_arr;
}
int mysearch_val(int arr[], unsigned int size, int num_to_s)
{
    int index = -1;
    int tmpindex;
    int divider = size / 2;
    if (arr[divider] == num_to_s)
        return divider;
    else if (arr[divider] > num_to_s) {
            tmpindex = divider / 2;
         } else if (arr[divider] < num_to_s) {
                tmpindex = divider;
                divider /= 2;
                tmpindex += divider;
                }
    if (arr[tmpindex] == num_to_s)
        return tmpindex;
    if (num_to_s < arr[tmpindex]) {
        for (int i = tmpindex - 1; i > tmpindex - divider; i--) {
            if (arr[i] == num_to_s)
                return i;
        }
    }
    if (num_to_s > arr[tmpindex]) {
        for (int i = tmpindex + 1; i < tmpindex + divider; i++) {
            if (arr[i] == num_to_s)
                return i;
        }
    }
    return index;
}

