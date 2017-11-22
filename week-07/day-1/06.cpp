#include <iostream>
#include <stdexcept>

using namespace std;

// Create a function which throws a built-in exception
// In the main(), put that function in a try block
// Also in the main() catch, what your function throws


void stdthrow() throw(runtime_error)
{
    float a = 1.1;
    if (a > 1)
        throw runtime_error("a is over limit!");
}
int main() {
    try {
        stdthrow();
    }
    catch(runtime_error &e) {
        cout << e.what();
    }

	return 0;
}

