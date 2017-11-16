#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Create a Shape class, inherit two derived class from it
// One should be Circle, and the other one is Triangle
// For each derived class, implement a calc_area() method
// which calculates the area of the shape and stores it inside
// the class (so it is a private method)
class Shape {
    public:
        virtual void calc_area() = 0;
    protected:
        vector<int> values;
};
class Circle : private Shape {
    void calc_area() {
        values.push_back(values[0] * values[0] * 3.14);
    }
};
class Triangle : private Shape {
    void calc_area() {
        int a = values[0];
        int b = values[1];
        int c = values[2];
        values.push_back(sqrt(a * a + b * b - c * c)); // not the real method...
    }
};
int main()
{
    Circle c;
    Triangle t;
    //c.calc_area();
    //t.calc_area(); //these dont work, as functionc are private

    return 0;
}

