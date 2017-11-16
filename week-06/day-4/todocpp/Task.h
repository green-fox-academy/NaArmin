#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>

using namespace std;

class Task
{
    public:
        Task(string descript);
        Task(string descript, int prio);
        void setprio(int);
        void setdone();
        int getprio();
        bool getdone();
        ~Task();

    protected:

    private:
        string descript;
        int prio;
        bool done;
};

#endif // TASK_H
