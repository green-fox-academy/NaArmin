#include <iostream>
#include "Student.h"

using namespace std;

int main()
{
    Student st;
    st.add_grade(3);
    st.add_grade(4);
    st.add_grade(1);
    cout << st.get_average() << endl;
    return 0;
}
