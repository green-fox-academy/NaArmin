#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student {
        vector<int> grades;
    public:
        void add_grade(int grade) {
            if (grade < 1 || grade > 5)
                cout << "Grade is not between 1 and 5." << endl;
            else
                grades.push_back(grade);
            return;
        }
        float get_average() {
            float sum = 0;
            for (unsigned int i = 0; i < grades.size(); ++i)
                sum += grades[i];
            return sum / grades.size();
        }
        ~Student() {
            cout << "student removed";
        }
};
int main() {
    // Create a student Class
    // that has a method `add_grade`, that takes a grade from 1 to 5
    // an other method `get_average`, that returns the average of the
    // grades
  return 0;
}

