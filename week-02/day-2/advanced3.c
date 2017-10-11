#include <stdio.h>

int main()
{
    int arr[20];
    int freq[20];
    int realsize = 0;
    // TODO: write a program wich asks for a number, that will be the real size of the array (20 elements are allocated, that's the maximum size)
    // Then load up the array with integer values
    // Finally print all unique elements in array
    printf("Specify the array's size (max 20)! ");
    scanf("%d", &realsize);
    if (realsize < 1 || realsize > 20)
        return 0;
    for (int i = 0; i < realsize; i++) {
        arr[i] = i % 9;
        printf("%d\t", arr[i]);
    }
    printf("\nUnique elements:\n");
    for (int i = 0; i < realsize; i++) {
        freq[i] = 0;
        for (int j = 0; j < realsize; j++) {
            if (arr[i] == arr[j])
                freq[i]++;
        }
    }
    for (int i = 0; i < realsize; i++) {
        if (freq[i] == 1)
            printf("%d\t", arr[i]);
    }
    return 0;
}

