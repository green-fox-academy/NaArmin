#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int randnums[12];
    int tmpnum;
    srand((unsigned int)&tmpnum); // randomizing using memory address
    for (int i = 0; i < 12; i++) {
        randnums[i] = rand() % 100;
        printf("| %d ", randnums[i]);
    }
    printf("\nAfter sort:\n");
    for (int i = 11; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (randnums[j] > randnums[j + 1]) {
                tmpnum = randnums[j];
                randnums[j] = randnums[j + 1];
                randnums[j + 1] = tmpnum;
            }
        }
    }
    for (int i = 0; i < 12; i++)
        printf("| %d ", randnums[i]);
    return 0;
}

