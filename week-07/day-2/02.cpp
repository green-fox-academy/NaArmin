#include <iostream>
using namespace std;

// Create 3 functions: each should take respectively 2, 3 and 4 strings.
// Each should return a string that contains all the input string concatenated.
// (Combined into one in a linear order.)
// Write code that showcases how this works and prints out the result of the function.
string concat(string st1, string st2)
{
    return st1 + st2;
}
string concat(string st1, string st2, string st3)
{
    return st1 + st2 + st3;
}
string concat(string st1, string st2, string st3, string st4)
{
    return st1 + st2 + st3 + st4;
}
int main() {

    cout << concat("alma", "fa") << endl;
    cout << concat("tukor", "furo", "gep") << endl;
    cout << concat("pek", "lapat", "at", "mero");
	return 0;
}

