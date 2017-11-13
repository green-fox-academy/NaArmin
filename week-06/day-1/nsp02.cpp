#include <iostream>

// Create your own namespace, called Person
// store your name as a string
// your age as an integer
// and your favorite number as an integer
// write them out in main()
using namespace std;
namespace Person {
    string name = "Nagymihaly Armin";
    int age = 33;
    int favnum = 12;
    }

int main()
{
    using namespace Person;
    cout << name << endl << "Age: " << age << endl << "Fav. number: " << favnum;
    return 0;
}

