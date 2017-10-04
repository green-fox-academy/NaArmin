#include <stdio.h>
#include <stdint.h>

int main() {
    uint8_t number = 254;
	uint8_t result;

	result = number + 23;
	// Check the result with printf
    printf("%d\n", result);
 	// What happened?!
        // the number has "turned over" at 255, so it is 21 again.

	// Try again with different datatype
	uint16_t result_16 = number + 23;
	// Check the result with printf
    printf("%d\n", result_16);
	// What happened and why?
        // the result is now OK, because variable can store max. the value 65535.
	//----------------------------------------
	int8_t number_negative = number;
	// Check the result with printf
    printf("%d\n", number_negative);
	// What happened and why?
        // we switched to signed integer 8bit, so it is /127 in this case + the other 7bits value.
    return 0;
}
