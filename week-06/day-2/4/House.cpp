#include "House.h"

House::House(string address, unsigned int area) {
     this->address = address;
     this->area = area;
     price = area * 400;
}
unsigned int House::get_price() {
     return this->price;
}
House::~House() {
     cout << endl << "Instance of House removed";
}
