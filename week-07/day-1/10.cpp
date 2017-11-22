#include <iostream>
#include <stdexcept>

using namespace std;

/**
 * Create a function that prints out the fist "N" positive odd numbers.
 * It should take the "N" number as a parameter, and print the output to the console.
 *
 * The output should look like this for 5 as parameter:
 *   1, 3, 5, 7, 9
 *
 * Non-positive "N" numbers should be treated as errors, handle it!
 */
void positiveodd(int) throw(invalid_argument);

int main() {

    try {
        positiveodd(5);
    }
    catch(invalid_argument &err) {
        cout << err.what();
    }
  return 0;
}
void positiveodd(int n) throw(invalid_argument)
{
    if (n < 0)
        throw invalid_argument("This is not a positive number!");
    for (int i = 0; i < n; ++i) {
        cout << 1 + (i * 2);
        if (i != n - 1)
            cout << ", ";
    }
}

