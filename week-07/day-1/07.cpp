#include <iostream>

using namespace std;
//Try to run the following code!

int main () {
    int i = 200;
    int int_array[5] = {1, 2, 3, 4, 5};
    try {
        if (i + 1 > sizeof(int_array) / sizeof(int))
            throw i;
        cout << int_array[i];
    }
    catch(int e) {
        cout << "The index " << e << " is beyond array boundary.";
    }
    return 0;
}

//The program should compile but crash!
//Create a solution for this problem using try-catch block!

