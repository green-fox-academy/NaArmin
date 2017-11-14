#ifndef CAR_H
#define CAR_H
#include <iostream>

using namespace std;

class Car
{
    public:
        Car(string, int);
        void run(unsigned int);
        ~Car();
    private:
        string type;
        unsigned int km;
};

#endif // CAR_H
