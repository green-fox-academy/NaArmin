#include <iostream>

using namespace std;
// Take the Integer class from the previous exercise and create two operators for it:
// a + operator that takes and Integer& and adds it's member variables value to this.
// a + operator that takes an int and adds it's value to the member variable of this.
//
// Consider what the return value of the operator should be: Integer& or void? Or something else?
// Make it so that the code below compiles and works.

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
    Integer& operator + (int num) {
        inum += num;
        return *this;
    }
    Integer& operator + (Integer& second) {
        inum += second.getnum();
        return *this;
    }
};
int main() {
    Integer a(12);
    Integer b(12);

    cout << (a + b).getnum() << endl;
    cout << (a + 12).getnum() << endl;
    cout << (a + b + 12).getnum() << endl;
	return 0;
}

