#include <iostream>
#include "Circle.h"

using namespace std;

int main()
{
    Circle cr(3.3);
    cout << cr.get_circumference() << endl << cr.get_area() << endl;
    return 0;
}
