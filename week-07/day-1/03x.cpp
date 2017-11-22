#include <iostream>
#include <stdexcept>

using namespace std;

// Write a try - catch block.
// Throws a bulit-in exception in the try block
// Catch it in the catch block and write it out.
// Don't forget includes

int main() {
    try {
        float d;
        cout << "Divider? ";
        cin >> d;
        if (d == 0)
            throw invalid_argument("divider is zero!");
        else if (d < 1)
            throw 'f';
        else if (d > 1000)
            throw 0;
        cout << "Result: ";
    }
    
    catch(...) {
        cout << "Some error.";
    }
	return 0;
}

