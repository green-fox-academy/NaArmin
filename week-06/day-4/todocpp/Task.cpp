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
Task::~Task()
{
    cout << "  task deconstructed  ";
}
