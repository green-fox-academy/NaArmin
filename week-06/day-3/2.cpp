#include <iostream>
#include <vector>

using namespace std;

class Shape {
    public:
        virtual void calc_area() = 0;
    protected:
        vector<float> values;
};
class Circle : private Shape {
        void calc_area() {
            values.push_back(values[0] * values[0] * 3.14);
            return;
        }
    public:
        void getradius() {
            float r;
            cout << "Give a radius value! ";
            cin >> r;
            values.push_back(r);
            calc_area();
            return;
        }
};
class Triangle : private Shape {
        void calc_area() {
            float a = values[0];
            float b = values[1];
            values.push_back(a * b / 2);
            return;
        }
        float getheight() {
            float h;
            cout << "Give a height value! ";
            cin >> h;
            return h;
        }
        float getbase() {
            float b;
            cout << "Give a base value! ";
            cin >> b;
            return b;
        }
    public:
        void getbasehgt() {
            values.push_back(getbase());
            values.push_back(getheight());
            return;
    }
};
int main()
{
    Circle c;
    Triangle t;
    c.getradius();
    t.getbasehgt();
    return 0;
}

