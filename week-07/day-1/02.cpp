#include <iostream>
using namespace std;

// Write a try - catch block.
// Throw an char in the try block
// Catch it in the catch block and write it out.

int main() {
    int x = 1;
    int z = 0;
    try {
        if (z == 0)
            throw 'r';
        cout << x / z;
    }
    catch(char c) {
        cout << c;
    }
	return 0;
}
