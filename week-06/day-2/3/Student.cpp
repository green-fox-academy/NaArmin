#include "Student.h"

Student::Student(string name, unsigned int age) {
      this->age = age;
      this->name = name;
    }
string Student::greet() {
        return "Hello my name is " + name;
    }
Student::~Student() {
        cout << "Student instance removed.";
    }
