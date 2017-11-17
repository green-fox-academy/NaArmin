#include <iostream>
#include <string>
#include "TasksList.h"

using namespace std;

void showcmds();

int main()
{
    string usercmd;
    TasksList todolst;
    showcmds();
    while (true) {
        getline(cin, usercmd);
        if (usercmd[0] == '-') {
            switch (usercmd[1]) {
            case 'a':
                if (usercmd[2] == ' ')
                    cout << "addt\n";
                else
                    cout << "Misspelled command!" << endl;
                break;
            case 'w':
                if (usercmd[2] == 'r')
                    cout << "write file\n";
                else
                    cout << "Misspelled command!" << endl;
                break;
            case 'q':
                if (usercmd[2] == 0)
                    return 0;
                else
                    cout << "If you want to quit, dont type anything after 'q' please!" << endl;
                break;
            default:
                cout << "Invalid command!" << endl;
            }
        }
        else
            cout << "Input is not interpretable!" << endl;
    }
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
