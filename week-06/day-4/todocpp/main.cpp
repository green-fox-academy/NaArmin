#include <iostream>
#include <string>
#include "TasksList.h"

using namespace std;

void showcmds();
int commandparse(string);

int main()
{
    showcmds();
    return 0;
}
void showcmds()
{
    cout << "Todo application" << endl;
    cout << "====================" << endl;
    cout << "Commands:" << endl;
    cout << "-a   Add a new task" << endl;
    cout << "-wr  Write current todos to file" << endl;
    cout << "-rd  Read todos from a file" << endl;
    cout << "-l   List all the tasks" << endl;
    cout << "-e   Empty the list" << endl;
    cout << "-rm  Remove a task" << endl;
    cout << "-c   Complete a task" << endl;
    cout << "-p   Add priority to a task" << endl;
    cout << "-lp  List all the tasks by priority" << endl;
    cout << "-q   Quit program" << endl;
}
int commandparse(string input)
{

}
