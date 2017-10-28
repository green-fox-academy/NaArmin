#include <stdio.h>
#include <string.h>
#include <windows.h>

struct task {
    char text[70];
    };
struct task list[10];
int tasknum = 0;

void help();
void addtask(char *descript);
void listtasks();
void emptytasks();
void deltask(char *index);
void savefile();
void loadfile();

int main()
{
    char *command, *param, buffer[100];
    system("clear");
    help();
    while (1) {
        gets(buffer);
        command = strtok(buffer, " ");
        param = strtok(NULL, "\"");
        if (strcmp(command, "-q") == 0)
            break;
        if (strcmp(command, "-a") == 0)
            if (tasknum < 10)
                addtask(param);
            else
                puts("Sorry, but you reached the maximal 10 tasks!");
        if (strcmp(command, "-l") == 0)
            listtasks();
        if (strcmp(command, "-e") == 0)
            emptytasks();
        if (strcmp(command, "-rm") == 0)
            deltask(param);
        if (strcmp(command, "-rd") == 0)
            loadfile();
        if (strcmp(command, "-wr") == 0) {
            savefile();
            puts("File saved.");
        }
    }
    return 0;
}
void addtask(char *descript)
{
    if (descript == NULL) {
        puts("No task specified, nothing created!");
        return;
    }
    strcpy(&list[tasknum].text, descript);
    list[tasknum].text[68] = 0;
    tasknum++;
}
void listtasks()
{
    puts("List by number\n====================\nNum | Tasks");
    for (int i = 0; i < tasknum; i++)
        printf("%2d    %s\n", i + 1, &list[i].text);
}
void emptytasks()
{
    tasknum = 0;
    puts("You have nothing to do today! ;)");
}
void deltask(char *index)
{
    int idx;
    if (index == NULL) {
        puts("No task specified, nothing removed!");
        return;
    }
    idx = atoi(index);
    if (idx < 1) {
        puts("Index is not a number, nothing removed!");
        return;
    }
    if (idx > tasknum) {
        puts("There are less tasks in your list, nothing removed!");
        return;
    } else {
        for (int i = idx - 1; i < tasknum; i++)
            list[i] = list[i +  1];
        tasknum--;
        }
}
void loadfile()
{
    char line_fromfile[70];
    FILE *fp;
    fp = fopen("todos", "r");
    if (fp == NULL) {
        puts("File of todo does not exist!");
        return;
    }
    tasknum = 0;
    while (fp != NULL) {
        tasknum++;
        if (!fgets(line_fromfile, 69, fp)) {
            tasknum--;
            break;
        }
        strcpy(&list[tasknum - 1].text, strtok(line_fromfile, '\n'));
    }
    fclose(fp);
    printf("%d task(s) read.\n", tasknum);
}
void savefile()
{
    FILE *fp;
    fp = fopen("todos", "w");
    for (int i = 0; i < tasknum; i++)
        fputs(&list[i].text, fp);
        fputc('\n', fp);
    fclose(fp);
}
void help()
{
    puts("Todo application\n====================\nCommands:\n  -a   Adds a new task\n  -wr  Write current todos to file");
    puts("  -rd  Read todos from a file\n  -l   Lists all the tasks\n  -e   Empty the list\n  -rm  Removes a task");
    puts("  -c   Completes a task\n  -p   Add priority to a task\n  -lp  Lists all the tasks by priority\n  -q   Quit program\n");
}
