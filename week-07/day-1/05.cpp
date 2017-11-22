#include <iostream>
using namespace std;

// Create a function which throws an char
// In the main(), put that function in a try block
// Also in the main() catch, what your function throws

void charthrow() throw(char)
{
    int a = 1;
    if (a > 0)
        throw 'B';
}
int main() {
    try {
        charthrow();
    }
    catch(char e) {
        cout << e;
    }

	return 0;
}

