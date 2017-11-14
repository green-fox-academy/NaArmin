#include <iostream>
#include "Pirate.h"

using namespace std;

int main()
{
    Pirate pir;
    for (int i = 1; i < 11; i++) {
        cout << pir.hows_goin_mate() << endl;
        pir.drink_rum();
    }
    return 0;
}
