#include <stdlib.h>

// Write a function called `sum` that sum all the numbers
// until the given parameter which you store in a .h file

int sum(int until_num)
{
    int tmp_sum = 0;
    for (int i = 0; i < until_num + 1; i++)
        tmp_sum += i;
    return(tmp_sum);
}
