#include <iostream>

using namespace std;

/**
 * Please create a program that asks for a count when it starts.
 * It should ask for a number count times, then it shoud print the average of the nubmers.
 * It should delete any dynamically allocated resource before the program exits.
 */

int main()
{
    int *ptr = NULL;
    int len;
    cout << "How many numbers will you enter? ";
    cin >> len;
    ptr = new int[len];
    cout << "Enter numbers!" << endl;
    for (int i = 0; i < len; i++)
        cin >> ptr[i];
    for (int i = 1; i < len; i++)
        ptr[0] += ptr[i];
    cout << "Average is " << ptr[0] / (float)len;
    delete ptr;
    return 0;
}

