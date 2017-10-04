#include <stdio.h>
#include <stdint.h>

int main() {
	int a = 654;
	uint64_t b = 654987312;
	// Tell if the reminder of b devided by a is 3
	if (b % a == 3)
        printf("%s\n", "remainder is 3!");
    else
        printf("%s\n", "remainder not 3!");
	return 0;
}
