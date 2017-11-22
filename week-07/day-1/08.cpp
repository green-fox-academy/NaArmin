#include <iostream>
#include <stdexcept>

using namespace std;

/* Write a function which is called "get_fibonacci_number". It returns the "N"th
 * Fibonacci number, where "N" is received as a paramter.
 * For example:
 *  - get_fibonacci_number(1) returns 0
 *  - get_fibonacci_number(2) returns 1
 *  - get_fibonacci_number(3) returns 1
 *  - get_fibonacci_number(4) returns 2
 *  - get_fibonacci_number(5) returns 3
 *  - get_fibonacci_number(6) returns 5
 *
 *  If the function gets invalid parameter
 *  Negative numbers are invalid parameters.
 *  It should throw an exception
 */
unsigned int get_fibonacci_number(int) throw(invalid_argument);

int main() {
    int i;
    try {
        cout << "Fibonacci No: ";
        cin >> i;
        cout << get_fibonacci_number(i) << endl;
    }
    catch(invalid_argument &err) {
        cout << err.what();
    }
	return 0;
}
unsigned int get_fibonacci_number(int pos) throw(invalid_argument)
{
    unsigned int a = 0;
    unsigned int b = 1;
    unsigned int r = 1;
    if (pos < 0)
        throw invalid_argument("Negative numbers are not allowed!");
    else if (pos == 0)
        return a;
    else if (pos == 1)
        return b;
    for (int i = 1; i < pos; ++i) {
        r = a + b;
        if (i % 2 == 1) {
            a = r;
        } else {
            b = r;
        }
    }
    return r;
}

