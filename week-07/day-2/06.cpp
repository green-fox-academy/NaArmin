#include <iostream>

using namespace std;
// Take the Integer class from the previous exercise and add two methods:
// One which takes an Integer& parameter and adds the value of it to the member variable of this.
// One which takes an int and adds the value of it to the member variable of this.
//
// Write code which uses them both and Prints out the results respectively.

class Integer {
    int inum;
  public:
    Integer() {
        inum = 0;
    }
    Integer(int pnum): inum(pnum) {
    }
    Integer(Integer& param): inum(param.inum) {
    }
    int getnum() {
        return inum;
    }
    void addnum(Integer& a) {
        inum += a.getnum();
    }
    void addnum(Integer& a, Integer& b) {
        inum += a.getnum() + b.getnum();
    }
    void addnum(Integer& a, Integer& b, Integer& c) {
        inum += a.getnum() + b.getnum() + c.getnum();
    }
    void addnum(Integer& a, Integer& b, Integer& c, Integer& d) {
        inum += a.getnum() + b.getnum() + c.getnum() + d.getnum();
    }
    void addnum(Integer& a, Integer& b, Integer& c, Integer& d, Integer& e) {
        inum += a.getnum() + b.getnum() + c.getnum() + d.getnum() + e.getnum();
    }
    void addnum(int num) {
        inum += num;
    }
};
int main() {
    Integer i1(1);
    Integer i2(2);

    i1.addnum(10);
    cout << "i1 + 10 = "  << i1.getnum() << endl;
    i1.addnum(i2);
    cout << "i1 + i2 = "  << i1.getnum() << endl;
	return 0;
}

