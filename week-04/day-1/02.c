#include <stdio.h>

int main() {
    int number = 1234;
    int* number_pointer = &number;
    //TODO:
    // print the value of number using the "number_pointer"
    printf("the value is %d, the address is %p, %x.", *number_pointer, number_pointer, &number);
    return 0;
}

