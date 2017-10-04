#include <stdio.h>
#include <stdint.h>

int main() {
	uint16_t number = 254;
	// if number can't be represented with 8bits
	// print 'longer than 8bits' otherwise print 'ok'
	printf("%s\n", (number > 127 || number < -127) ? "Longer than 8 bits" : "OK");
	return 0;
}
