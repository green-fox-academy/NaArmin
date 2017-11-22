#include <iostream>
using namespace std;

// Create a class Float based on the examples from the two previous files and Your experiences from before.
// Try out all it's functions incrementally and print out the results in main().
// Good coding! :)
class Float {
    float val;
  public:
    float get()
    {
        return val;
    }
    void set(float pnum)
    {
        val = pnum;
    }
    Float()
    {
        val = 0;
    }
    Float(float pnum)
    {
        val = pnum;
    }
    Float(Float& pfloat)
    {
        val = pfloat.get();
    }
    Float& operator - (Float& second) {
        val -= second.get();
        return *this;
    }
    Float& operator - (float second) {
        val -= second;
        return *this;
    }
    Float& operator + (Float& second) {
        val += second.get();
        return *this;
    }
    Float& operator + (float second) {
        val += second;
        return *this;
    }
    Float& operator = (Float& second) {
        val = second.get();
        return *this;
    }
};

int main() {

    Float a;
    Float b(1.11);
    Float c(b);
    cout << a.get() << ", " << b.get() << ", " << c.get() << endl;
    a.set(3.141);
    cout << a.get() << endl;
    cout << a.get() + b.get() << endl;
    cout << (a + b).get() << " a: " << a.get() << endl;
    c.set((a - b - b).get());
    cout << c.get() << endl;
    a - b;
    cout << a.get() << endl << b.get() << endl;
    c = a;
    cout << c.get() << endl;
    b + 2.5;
    cout << "b + 2.5 = " << b.get() << endl;
    b - 2.1;
    cout << "b - 2.1 = " << b.get();
  return 0;
}

