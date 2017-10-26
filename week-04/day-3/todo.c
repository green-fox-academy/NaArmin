#include <stdio.h>
#include <string.h>
#include <windows.h>

struct task {
    char *text;
    };
struct task list[10];

void help();

int main()
{
    char *command, *param, buffer[100];
    system("clear");
    help();
    gets(buffer);
    command = strtok(buffer, " ");
    param = strtok(NULL, "\"");
    puts(command);
    puts(param);
}
void help()
{
    puts("Todo application\n====================\nCommands:\n  -a   Adds a new task\n  -wr  Write current todos to file");
    puts("  -rd  Read todos from a file\n  -l   Lists all the tasks\n  -e   Empty the list\n  -rm  Removes a task");
    puts("  -c   Completes a task\n  -p   Add priority to a task\n  -lp  Lists all the tasks by priority\n exit  Quit program\n");
}

