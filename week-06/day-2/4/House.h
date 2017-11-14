#ifndef HOUSE_H
#define HOUSE_H
#include <iostream>

using namespace std;

class House
{
    public:
        House(string, unsigned int);
        unsigned int get_price();
        ~House();
    private:
        string address;
        unsigned int area;
        unsigned int price;
};

#endif // HOUSE_H
