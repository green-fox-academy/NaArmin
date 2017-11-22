#include <iostream>
#include <stdexcept>

using namespace std;

void stdthrow() throw(int, char, runtime_error)
{
    float a = 1.1;
    if (a == 1)
        throw runtime_error("a is over limit!");
    else if (a < 0)
        throw 'z';
    else if (a > 10)
        throw 10;
}
int main() {
    try {
        stdthrow();
    }
    catch(...) {
        cout << "som error.";
    }

	return 0;
}

