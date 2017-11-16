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
            values.insert(values.begin(), values[0] * values[0] * 3.14);
            return;
        }
    public:
        void setradius() {
            float r;
            cout << "Give a radius value! ";
            cin >> r;
            values.insert(values.begin(), r);
            calc_area();
            return;
        }
        virtual float how_much_to_paint(float price) {
                setradius();
                return values[0] * price;
        }
};
class Triangle : private Shape {
        void calc_area() {
            float a = values[0];
            float b = values[1];
            values.insert(values.begin(), a * b / 2);
            return;
        }
        float setheight() {
            float h;
            cout << "Give a height value! ";
            cin >> h;
            return h;
        }
        float setbase() {
            float b;
            cout << "Give a base value! ";
            cin >> b;
            return b;
        }
    public:
        void setbasehgt() {
            values.insert(values.begin(), setbase());
            values.insert(values.begin(), setheight());
            calc_area();
            return;
        }
        float how_much_to_paint(float price) {
            setbasehgt();
            return values[0] * price;
        }
};
int main()
{
    Circle c;
    Triangle t;
    
    cout << c.how_much_to_paint(10.3) << endl;
    cout << t.how_much_to_paint(10.3) << endl;
    return 0;
}

