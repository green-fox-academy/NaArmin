#include "Circle.h"
#include <iostream>

using namespace std;

Circle::Circle(float radius)
{
    this->radius = radius;
}
float Circle::get_circumference() {
        return radius * 2 * 3.14159;
}
float Circle::get_area() {
        return radius * radius * 3.14159;
}
Circle::~Circle() {
        cout << "Circle instance removed.";
}
