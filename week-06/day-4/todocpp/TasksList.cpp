#include "TasksList.h"

TasksList::TasksList()
{
    numtasks = 0;
}
void TasksList::addtask(string usrcommand) {
    string name;
    for (int i = 3; i < usrcommand.length(); i++)
        name += usrcommand[i];
    Task t(name);
    tlist.push_back(t);
}
void TasksList::listtasks() {
    cout << "List by number\n ====================\n Num | Tasks" << endl;
    for (unsigned int i = 0; i < tlist.size(); i++)
        cout << i << " " << tlist[i].getname() << endl;
}
void TasksList::remtask() {}
void TasksList::emptylist() {}
void TasksList::writefile() {}
void TasksList::readfile() {}
void TasksList::completetask() {}
void TasksList::addprio() {}
void TasksList::listprio() {}
TasksList::~TasksList()
{
    cout << "    taskList deconstructed  ";
}
