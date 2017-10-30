#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int rands[5];
    int tmp;
    int siz = (sizeof(rands) / sizeof(int));

    for (int i = 0; i < 5; i++)
        rands[i] = rand();
    for (int i = 0; i < 5; i++)
        printf("%d | ", rands[i]);
    printf("\n");
    for (int i = 0; i < siz / 2; i++) {
        tmp = rands[i];
        rands[i] = rands[siz - 1 - i];
        rands[siz - 1 - i] = tmp;
    }
    for (int i = 0; i < 5; i++)
        printf("%d | ", rands[i]);
    return 0;
}

