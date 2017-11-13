#include <iostream>

// Create your own namespace, called Mark
// store your name as a string
// your age as an integer
// and your favorite number as an integer
//
// Create your own namespace, called Maria
// store your name as a string
// your age as an integer
// and your favorite number as an integer
//
// create a function that can add the two age, and returns it
using namespace std;

namespace Mark {
    string name = "Mark";
    int age = 39;
    int favnum = 5;
    }
namespace Maria {
    string name = "Maria";
    int age = 36;
    int favnum = 8;
    }
int addages();

int main()
{

    cout << "Sum of ages : " << addages();
    return 0;
}
int addages()
{
    int sum = Mark::age + Maria::age;
    return sum;
}

