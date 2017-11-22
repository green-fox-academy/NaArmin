#include <iostream>
#include <string>
using namespace std;

// Write a function that can throw two kinds of exceptions: int and const char*
// It should receive an integer.
// It should return a string from the char* array defined below.
// If the integer is larger than 5, throw an integer exception. The value of the exception should be how much larger it is.
// If the integer is less than 0, it should throw a const char* exception stating, that it is a negative number.
//
// Illustrate both cases in the main function.
// HINT: Put each protected code segmetn in a new try-catch block.

const char* sentence[6] = {"What", "a", "pleasant", "surprie", "this", "is."};

string wordsentence(int pos) throw(int, const char*);

int main()
{
    try {
    cout << wordsentence(6) << endl << wordsentence(-1) << endl  << wordsentence(3);
    }
    catch(int p) {
        cout << p << " indexes";
    }
    //try {
    //cout << wordsentence(-1) ;
    //}
    catch(char* str) {
        cout << str;
    }
    cout << endl  << wordsentence(3);

    return 0;
}
string wordsentence(int pos) throw(int, const char*)
{
    if (pos > (int)sizeof(sentence) / (int)sizeof(char*) + 1)
        throw pos - (sizeof(sentence) / sizeof(char*));
    if (pos < 0)
        throw "Given parameter is negative.";
    return sentence[pos];
}
