#include <stdio.h>

int main() {
    int i = 320;
    float c;
    printf("= Fahrenheit       Celsius =\n");
    while (i > 100) {
        c = (i - 32) / 1.8;
        printf("  %3d\t\t   %3.1f\n", i, c);
        i -= 20;
    }
	return 0;
}
