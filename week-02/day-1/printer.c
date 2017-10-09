#include <stdio.h>
#include <stdarg.h>
#include "C:\Users\Valaki\greenfox\NaArmin\week-02\day-1\printer.h"


void printer(int, ...);

int main()
{
    printer(num_params, n1, n2, n3, n4, n5, n6);
    return 0;
}
void printer(int param_num, ...)
{
    va_list ap;
    va_start(ap, param_num);
    for (int i = 0; i < param_num; i++)
        printf("%d\n", va_arg(ap, int));
    va_end(ap);
}

