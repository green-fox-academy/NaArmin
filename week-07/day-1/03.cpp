#include <iostream>
#include <stdexcept>

using namespace std;

// Write a try - catch block.
// Throws a bulit-in exception in the try block
// Catch it in the catch block and write it out.
// Don't forget includes

int main() {
    try {
        int d;
        cout << "Divider? ";
        cin >> d;
        if (d == 0)
            throw invalid_argument("divider is zero!");
        cout << "Result: ";
    }
    catch(invalid_argument &err) {
        cout << err.what();
    }
	return 0;
}

