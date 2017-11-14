#include <iostream>
#include "Student.h"

using namespace std;

int main()
{
    Student st("Mark", 24);
    cout << st.greet() << endl;
    return 0;
}
