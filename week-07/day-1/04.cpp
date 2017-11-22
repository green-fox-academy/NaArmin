#include <iostream>
using namespace std;

// Create a function which throws an integer
// In the main(), put that function in a try block
// Also in the main() catch, what your function throws
void intthrow() throw(int)
{
    int a = 1;
    if (a > 0)
        throw 9;
}
int main() {
    try {
        intthrow();
    }
    catch(int e) {
        cout << e;
    }

	return 0;
}

