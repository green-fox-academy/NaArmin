#include <stdio.h>

int main() {
	int k = 1521;
	// tell if k is dividable by 3 or 5
	printf("%s", (k % 3) ? "The k is NOT dividable by 3 " : "The k is dividable by 3 " );
	printf("%s\n", (k % 5) ? "and the k is NOT dividable by 5. " : "and the k is dividable by 5. " );
	return 0;
}
