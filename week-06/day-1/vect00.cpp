#include <iostream>
#include <vector>

using namespace std;

//create an integer vector with the size of 5 and print the 3rd element of it

int main()
{
    vector <int> vect;

    vect.push_back(6);
    vect.push_back(13);
    vect.push_back(1);
    vect.push_back(22);
    vect.push_back(8);
    cout << vect[2];
  return 0;
}

