#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    vector <int> vect;
    vect.reserve(10);
    int vsize = vect.size();
    for (int i = 0; i < vsize; i++)
        vect.push_back(rand() % 10);
    return 0;
}

