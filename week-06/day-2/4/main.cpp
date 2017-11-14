#include <iostream>
#include "House.h"

using namespace std;

int main()
{
    House house = House("Andrassy 66", 349);
    cout << house.get_price();
    return 0;
}
