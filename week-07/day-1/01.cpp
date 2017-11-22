#include <iostream>
using namespace std;

// Write a try - catch block.
// Throw an integer in the try block
// Catch it in the catch block and write it out.

int main() {
    try{
        int x = 0;
        int y = 0;
        if (y == 0)
            throw 3;
        cout << x / y;
    }
    catch(int err) {
        cout << err;
    }
	return 0;
}
