#include "Task.h"


Task::Task(string descript)
{
    this->descript = descript;
    this->prio = 0;
    this->done = false;
}
Task::Task(string descript, int prio)
{
    this->descript = descript;
    this->prio = prio;
    this->done = false;
}
string Task::getname() {
    return descript;
}
Task::~Task()
{
    cout << "  task deconstructed  ";
}
