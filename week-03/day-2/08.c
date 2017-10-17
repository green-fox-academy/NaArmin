#include <stdio.h>
#include <stdlib.h>

void transform (char str[], int original_base, int new_base);

//TODO: write a program, which transforms a number from a number system to another.
//use the stdlib.h functions, and take care of error handling (see the reference)
//the transform() function should print out the result.

int main()
{
    char str[20];
    int original_base;
    int new_base;

    printf("Give me a number to transform it in an other system: ");
    scanf("%s", str);
    printf("Give me the original base: ");
    scanf("%d", &original_base);
    printf("Give me the number of the new base: ");
    scanf("%d", &new_base);

    transform(str, original_base, new_base);
    return(0);
}
void transform (char str[], int original_base, int new_base)
{
    int newnum = strtol(str, NULL, original_base);
    char str_out[33];
    if (newnum == 0)
        printf("Given number was zero or not a number, or base was invalid!!! ");
    if (original_base == 0) {
        printf("You gave the number with hex or oct format specifier. ");
    }
    else {
        if(original_base < 2 || original_base > 36) {
            printf("\nOriginal base is out of accepted range!");
            return;
        }
    }
    if(new_base < 2 || new_base > 36) {
            printf("\nNew base is out of accepted range!");
            return;
    }
    itoa(newnum, &str_out, new_base);
    printf("\nThe number %s in base%d is %s in base%d.\n", str, original_base, str_out, new_base);
}

