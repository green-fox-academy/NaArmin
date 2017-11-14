#include "Student.h"
#include <iostream>

using namespace std;

void Student::add_grade(int grade) {
            if (grade < 1 || grade > 5)
                cout << "Grade is not between 1 and 5." << endl;
            else
                grades.push_back(grade);
            return;
        }
float Student::get_average() {
            float sum = 0;
            for (unsigned int i = 0; i < grades.size(); ++i)
                sum += grades[i];
            return sum / grades.size();
        }
Student::~Student() {
            cout << "student removed";
        }
