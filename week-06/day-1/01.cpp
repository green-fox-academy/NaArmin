#include <iostream>

using namespace std;

// Greet 3 of your classmates with this program, in three separate lines
// like:
//
// Hello, Esther!
// Hello, Mary!
// Hello, Joe!
// Store their names in separate string type variables


int main()
{
    string a, b, c;
    cout << "Give 3 names!" << endl;
    cin >> a >> b >> c;
    cout << "Hello " << a << "!" << endl;
    cout << "Hello " << b << "!" << endl;
    cout << "Hello " << c << "!" << endl;

    return 0;
}

