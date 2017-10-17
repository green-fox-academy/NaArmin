#include <stdio.h>
#include <stdlib.h>

void binary_adder (char *bin_op_1, char *bin_op_2);

//TODO: write a program which asks for two binary numbers.
//write a function, which prints out the sum of the 2 binary numbers.

int main()
{

    char a[20];
    char b[20];

    printf("Give me a binary number (19 bits max.): ");
    scanf("%s", &a);
    printf("Give me another binary number (19 bits max.): ");
    scanf("%s", &b);

    binary_adder(a, b);

    return(0);
}
void binary_adder (char *bin_op_1, char *bin_op_2)
{
    long a = strtol(bin_op_1, NULL, 2);
    long b = strtol(bin_op_2, NULL, 2);
    char outa[20], outb[20];
    printf("%20s\n%20s +\n", itoa(a, &outa, 2), itoa(b, &outb, 2));
    printf("--------------------\n%20s", itoa(a + b, &bin_op_1, 2));
}

