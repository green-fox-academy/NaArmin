#include <stdio.h>

/*
create a program which converts the fahrenheit to celsius
the output should look like this:
Fahrenheit       Celsius
  0               -17.8
 20                -6.7
 40                 4.4
 60                15.6
...
print out at least 10 lines
*/

int main() {
    int i = 0;
    float c;
    printf("= Fahrenheit       Celsius =\n");
    while (i < 240) {
        c = (i - 32) / 1.8;
        printf("  %3d\t\t   %3.2f\n", i, c);
        i += 20;
    }
	return 0;
}
