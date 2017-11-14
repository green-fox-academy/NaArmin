#ifndef PIRATE_H
#define PIRATE_H
#include <iostream>

using namespace std;

class Pirate
{
    public:
        void drink_rum();
        string hows_goin_mate();
        ~Pirate();
    private:
        int rum = 0;
};

#endif // PIRATE_H
