#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int rands[5];
    int target[7];
    int siz = (sizeof(rands) / sizeof(int));

    for (int i = 0; i < 5; i++)
        rands[i] = rand();
    
    for (int i = 0; i < siz; i++) {
        target[i + 1] = rands[i];
    }
    target[0] = target[6] = 42;
    for (int i = 0; i < 7; i++)
        printf("%d | ", target[i]);
    return 0;
}

