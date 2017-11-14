#include <iostream>
#include <string>

using namespace std;

class Circle {
    float radius;
  public:
    Circle(float radius) {
        this->radius = radius;
    }
    float get_circumference() {
        return radius * 2 * 3.14159;
    }
    float get_area() {
        return radius * radius * 3.14159;
    }
};
int main() {
    // Create a `Circle` class that takes it's radius as cinstructor parameter
    // It should have a `get_circumference` method that returns it's circumference
    // It should have a `get_area` method that returns it's area
  return 0;
}

