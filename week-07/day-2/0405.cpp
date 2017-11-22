#include <iostream>
using namespace std;

// Create a Class named Integer. It should have one int member variable.
// Create add() methods to it. They should take Integer& parameters.
// Make variations of add() method 1, 2, 3, 4 and 5 arguments respectively.
// All methods should add the value of the parameters to the member variable of this.
//
// Try them out. Write code that demonstrates how they work.

// Take the Integer class from the previous exercise.
// Create 3 constructors for them:
// One empty which sets the member varibale to 0;
// A copy constructor, that takes an Integer& argument
// A third one which takes an int as argument and makes the member variable equal to the int it took.
//
// Write code that uses these and prints out the value of the member variable of the integers created.
// (You will have to create a get method to do this appropriately.)


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
};
int main() {
    Integer i1(1);
    Integer i2(i1);
    Integer i3;
    Integer i4(10);
    Integer i5(i4);
    Integer i6;
    cout << "Integer class member 1 created with inputting 1, value: " << i1.getnum() << endl;
    cout << "Integer class member 2 created with copying prev. one, value: " << i2.getnum() << endl;
    cout << "Integer class member 3 created with no parameter, value: " << i3.getnum() << endl;
    cout << "Integer class member 4 created with inputting 10, value: " << i4.getnum() << endl;
    cout << "Integer class member 5 created with copying 4th, value: " << i5.getnum() << endl;
    cout << "Integer class member 6 created with no parameter, value: " << i6.getnum() << endl;
    i3.addnum(i2, i1);
    cout << "Member 3, after adding 1st and 2nd: " << i3.getnum() << endl;
    i1.addnum(i3);
    cout << "Member 1, after adding 3rd: " << i1.getnum() << endl;
    i3.addnum(i1, i2, i4);
    cout << "Member 3, after adding 1st, 2nd and 4th: " << i3.getnum() << endl;
    i5.addnum(i1, i2, i3, i4);
    cout << "Member 5, after adding 1st, 2nd, 3rd and 4th: " << i5.getnum() << endl;
    i6.addnum(i1, i2, i3, i4, i5);
    cout << "Member 6, after adding 1st, 2nd, 3rd, 4th and 5th: " << i6.getnum() << endl;
	return 0;
}

