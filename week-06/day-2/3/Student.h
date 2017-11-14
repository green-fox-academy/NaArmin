#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>

using namespace std;

class Student
{
    public:
        string name;
        unsigned int age;
        Student(string, unsigned int);
        string greet();
        ~Student();

};

#endif // STUDENT_H
