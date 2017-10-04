#include <stdio.h>

int main() {
	float w = 24;
	int out = 0;
	// if w is even increment out by one
	int w2;

	w2 = w;
	if ((w2 % 2 == 0) & (w - w2 == 0)) // check if w is really not an integer!
        out +=1;
	return 0;
}
