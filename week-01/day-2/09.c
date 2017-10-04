#include <stdio.h>

int main() {
	int i = 53625;
	// tell if it has 11 as a divisor
	printf("%s\n", (i % 11) ? "11 is not a divisor of it." : "11 is a divisor of it!");
	return 0;
}
