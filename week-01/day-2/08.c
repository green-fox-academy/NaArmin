#include <stdio.h>

int main() {
	int h1 = 350;
	int h2 = 200;
	// tell if the double of h2 is bigger than h1
	printf("%s\n", ((h2 * 2) > h1) ? "The double h2 is bigger." : "The double h2 is smaller.");
	return 0;
}
