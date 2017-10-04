#include <stdio.h>

int main() {
	int j1 = 10;
	int j2 = 3;
	// tell if j1 is higher than j2 squared and smaller than j2 cubed
	printf("%s\n", (j1 > (j2 *= j2)) ? "J1 is higher than J2 square." : "J1 is smaller than J2 square");
	printf("%s\n", (j1 > (j2 *= j2)) ? "J1 is higher than J2 cube." : "J1 is smaller than J2 cube");
	return 0;
}
