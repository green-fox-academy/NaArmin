#ifndef STUDENT_H
#define STUDENT_H
#include <vector>

using namespace std;

class Student
{
    public:
        void add_grade(int);
        float get_average();
        ~Student();

    private:
        vector<int> grades;

};

#endif // STUDENT_H
