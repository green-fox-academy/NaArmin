#include <stdio.h>
#include <stdint.h>

int main() {
    uint8_t x = 0b11001100;
    uint8_t y = 0b01010101;
	uint8_t z;

	// Be z equal to the bitwise and of x and y
    z = x & y;
	// Check the result with printf
    printf("%d\n", z);
    printf("%c", (z & 1<<7 ? '1' : '0'));
    printf("%c", (z & 1<<6 ? '1' : '0'));
    printf("%c", (z & 1<<5 ? '1' : '0'));
    printf("%c", (z & 1<<4 ? '1' : '0'));
    printf("%c", (z & 1<<3 ? '1' : '0'));
    printf("%c", (z & 1<<2 ? '1' : '0'));
    printf("%c", (z & 1<<1 ? '1' : '0'));
    printf("%c\n", (z & 1    ? '1' : '0'));
	// Be z equal to the bitwise or of x and y
    z = x | y;
	// Check the result with printf
    printf("%d\n", z);
    printf("%c", (z & 1<<7 ? '1' : '0'));
    printf("%c", (z & 1<<6 ? '1' : '0'));
    printf("%c", (z & 1<<5 ? '1' : '0'));
    printf("%c", (z & 1<<4 ? '1' : '0'));
    printf("%c", (z & 1<<3 ? '1' : '0'));
    printf("%c", (z & 1<<2 ? '1' : '0'));
    printf("%c", (z & 1<<1 ? '1' : '0'));
    printf("%c\n", (z & 1    ? '1' : '0'));

    return 0;
}
