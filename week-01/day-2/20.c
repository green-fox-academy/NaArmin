#include <stdio.h>
#include <stdint.h>

int main() {
	uint8_t z = 13;
	// if z is between 10 and 20 print 'Sweet!'
	if (z > 10 && z < 20)
        printf("%s\n", "Sweet!");
	// if less than 10 print 'More!',
	else if (z < 10)
            printf("%s\n", "More!");
	// if more than 20 print 'Less!'
            else
                printf("%s\n", "Less!");
	return 0;
}
