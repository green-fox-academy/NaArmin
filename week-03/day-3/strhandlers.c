#include <stdio.h>
#include <string.h>
#include "strhandlers.h"



int correctnum(char *a)
{
    char *ptr;
    float n = strtof(a, ptr);
    if (ptr == NULL)
        return 1;
    printf("Number contains non allowed characters!\n");
    return 0;
}
int numbers_ok() {
    if (strtof(&firstnum, NULL) != 0.0 && strtof(&secondnum, NULL) != 0.0)
        return 1;
    puts("Given numbers could not be recognized!");
    return 0;
}
