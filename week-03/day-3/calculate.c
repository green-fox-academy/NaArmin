#include "strhandlers.h"
#include "calculate.h"
#include <string.h>

float myadd(char *a, char *b)
{
    float n1, n2;
    if ((correctnum(a) == 1) && (correctnum(b) == 1)) {
        n1 = strtof(&a, NULL);
        n2 = strtof(&b, NULL);
        return n1 + n2;
    }
}
