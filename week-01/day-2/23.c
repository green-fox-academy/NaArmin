#include <stdio.h>
#include <stdint.h>

int main() {

	int girls_number = 12;
	int boys_number = 11;

	if (girls_number == 0 ) {
        printf("%s\n", "Sausage party");
        return 0;
	}
	if (girls_number + boys_number > 20) {
        if (girls_number == boys_number)
            printf("%s\n", "The party is excellent!");
        else
            printf("%s\n", "Quite cool party!");
	}
    else {
        printf("%s\n", "Average party...");
    }
return 0;
}
