#include <iostream>

using namespace std;

class ParentClass {
    public:
        virtual string first_func() {
            return "1st function virtual";
        }
        string second_func() {
            return "2nd function";
        }
};
class ChildClass : public ParentClass {
public:
    string first_func() {
        return "1st virtual function in Child";
    }
    string second_func() {
        return "2nd function in Child";
    }
};
int main()
{
    ParentClass *a = new ChildClass;
    cout << a->first_func() << endl << a->second_func();
    ChildClass c;
    ParentClass *b = &c;
    cout << endl << b->first_func() << endl << b->second_func();
    cout << endl << ((ChildClass*)a)->first_func() << endl << ((ChildClass*)a)->second_func();

    return 0;
}

