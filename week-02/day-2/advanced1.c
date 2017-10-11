#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[50];

    // TODO: write a program wich asks for a number, that will be the real size of the array (50 elements are allocated, that's the maximum size)
    // Then load up the array with integer values
	// print out the array
    // Then ask for a number, that will be the position, where you want the element to be deleted
    // handle the problem when trying to delete from invalid positions (e.g. negative number)
    // print out the the array after the deleting
    int realsize;
    int position;
    printf("Specify the array's size (max 50)! ");
    scanf("%d", &realsize);
    if (realsize < 1 || realsize > 50)
        return 0;
    for (int i = 0; i < realsize; i++) {
        arr[i] = rand() / 10;
        printf("[%2d]: %5d ", i + 1, arr[i]);
        if ((i + 1) % 6 == 0)
            printf("\n");
    }
    printf("\nElement to delete: ");
    scanf("%d", &position);
    if (position < 1 || position > realsize) {
        printf("This pos. does not exist!");
        return 0;
    }
    else {
        for (int i = position - 1; i < realsize; i++)
            arr[i] = arr[i + 1];
        realsize--;
    }
    puts("Element deleted.");
    for (int i = 0; i < realsize; i++) {
        printf("[%2d]: %5d ", i + 1, arr[i]);
        if ((i + 1) % 6 == 0)
            printf("\n");
    }
    return 0;
}

