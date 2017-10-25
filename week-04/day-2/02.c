#include <stdio.h>

enum CarType {VOLVO, TOYOTA, LAND_ROVER, TESLA};

struct Car {
  enum CarType type;
  double km;
  double gas;
};

// TODO:
// Write a function that takes a Car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level
void displaycar(struct Car *c);

int main() {
    struct Car *car1 = {"Toyota", 11111, 5};
    displaycar(&car1);
  return 0;
}
void displaycar(struct Car *c)
{
    printf("Car data:\n type: %s\n km: %d\n", c->type, c->km);
    if (c->type != "TESLA")
        printf(" gas level: %d", c->gas);
}

