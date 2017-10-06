#include <stdio.h>
int main()

/*
create a program which draws a diamond, like this:
      *
    * * *
  * * * * *
* * * * * * *
* * * * * * *
  * * * * *
    * * *
      *
*/
{
    for (int i = 1; i <= 7; i += 2) {
            for (int sp = 0; sp < 7 - i; sp+=2)
                printf("  ");
            for (int j = 0; j < i; j++)
                printf("* ");
            printf("\n");
    }
    for (int i = 7; i >= 1; i -= 2) {
            for (int sp = 0; sp < 7 - i; sp+=2)
                printf("  ");
            for (int j = 0; j < i; j++)
                printf("* ");
            printf("\n");
    }
    return 0;
}
