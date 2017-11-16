#include <iostream>
#include <vector>

using namespace std;

// Create a Human class which is a base class for
// SuperHuman and AquaHuman
// Create a virtual function in Human class called travelling()
// It should print out different ways to travel
// For example: Human is walking. SuperHuman is flying. AquaHuman is riding with dolphins.
class Human {
    public:
        virtual void travelling() {
            cout << "just walking....." << endl;
        }
};
class SuperHuman : public Human {
    public:
        void travelling() {
            cout << "flying!" << endl;
        }
};
class AquaHuman : public Human {
    public:
        void travelling() {
            cout << "riding with dolphins!" << endl;
        }
};
int main()
{
    Human hm;
    AquaHuman aqh;
    SuperHuman sup;
    hm.travelling();
    aqh.travelling();
    sup.travelling();
    Human *hma = &aqh;
    hma->travelling();
    return 0;
}

