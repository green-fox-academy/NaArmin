#ifndef TASKSLIST_H
#define TASKSLIST_H

#include <string>

using namespace std;

class TasksList
{
    public:
        TasksList();
        void addtask();
        void listtasks();
        void emptylist();
        void remtask();
        void writefile();
        void readfile();
        void completetask();
        void addprio();
        void listprio();
        ~TasksList();

    protected:

    private:
        int numtasks;
};

#endif // TASKSLIST_H
