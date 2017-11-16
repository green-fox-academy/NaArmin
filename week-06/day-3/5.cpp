#include <iostream>

using namespace std;

class Car {
    unsigned int age;
    unsigned int kms_runned;
    string manufacturer;
    unsigned int number_of_seats;
    int people_in = 0;
public:
    Car(unsigned int age, unsigned int kms_runned, string manufacturer, unsigned int seats) {
        this->age = age;
        this->kms_runned = kms_runned;
        this->manufacturer = manufacturer;
        number_of_seats = seats;
    }
    void increase_kms(unsigned int km) {
        kms_runned += km;
    }
    void add_person() {
        if (people_in == number_of_seats)
            cout << "-This car is already full! ";
        else
            people_in++;
    }
    void printkm() {
        cout << kms_runned << endl;
    }
};
int main()
{
    Car c1(4, 60000, "Smart", 2);
    Car c2(30, 260000, "Wartburg", 5);
    cout << "car 1 kms: ";
    c1.printkm();
    cout << "car 2 kms: ";
    c2.printkm();
    for (int i = 1; i < 7; i++) {
        cout << "Get in car 1 ";
        c1.add_person();
        cout << endl << "Get in car 2 " << endl;
        c2.add_person();
    }
    cout << "GO!" << endl;
    c1.increase_kms(25);
    c2.increase_kms(111);
    cout << "car 1 kms: ";
    c1.printkm();
    cout << "car 2 kms: ";
    c2.printkm();
    return 0;
}

