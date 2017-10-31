#include <stdio.h>
#include <stdlib.h>

void mybubblesort(int *arr[], unsigned int size);

int main(void)
{
    int randnums[16];
    srand((unsigned int)randnums[1]); // randomizing using memory garbage
    for (int i = 0; i < 12; i++) {
        randnums[i] = rand() % 100;
        printf("| %d ", randnums[i]);
    }
    printf("\nAfter sort:\n");
    mybubblesort(randnums, sizeof(randnums) / sizeof(randnums[0]));
    for (int i = 0; i < 12; i++)
        printf("| %d ", randnums[i]);
    return 0;
}
void mybubblesort(int *arr[], unsigned int size)
{
    int tmpnum;
    for (int i = size - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[j] > arr[j + 1]) {
                tmpnum = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmpnum;
            }
        }
    }
    return;
}

