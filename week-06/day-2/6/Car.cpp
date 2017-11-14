#include "Car.h"

Car::Car(string type, int km) {
        this->type = type;
        this->km = km;
    }
void Car::run(unsigned int km){
        this->km += km;
    }
Car::~Car() {
        cout << endl << "1 instance of Car removed.";
    }
