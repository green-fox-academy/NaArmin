#include <stdio.h>
#include <stdlib.h>

/*
write a program to check whether a given number is positive or negative
*/

int main()
{
    int a = 212;
    int b = abs(a);
    for (int i = 1; i <= b; i++) // done with cycle, yeah!
        a++;
    if (a == 0)
        printf("Negative or 0.");
    else
        printf("Positive.");

    return 0;
}
