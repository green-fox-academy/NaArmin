#include <stdio.h>
#include <string.h>

/**
Discover and understand the working method of this program
find and fix all the bugs
*/

struct task {
	char name[50];
	int done;
	int prio;
};

struct task tasks[100];
int num_tasks = 0;

void start_srceen();
void see_tasks();
void tasks_prio();
void new_task();
void rm_task(int index_task);
void complete_task(int index_cmp);

int main()
{
	char choice;
	while (1) {

		clear_screen();
		start_srceen();
		printf("Please enter what you want to do: ");
		choice = getchar() - 48;
		char c = 0;
		while (c != '\n')
			c = getchar();

		if (choice == 0) {
			printf("program will end now\n");
			break;
		} else if (choice == 1) {
			see_tasks();
			Sleep(4000);
		} else if (choice == 2) {
			tasks_prio();
			Sleep(4000);
		} else if (choice == 3) {
			new_task();
		} else if (choice == 4) {
			int index_task;
			printf("Enter the index of the task\n");
			scanf("%d", &index_task);
			getchar();
			rm_task(index_task);
		} else if (choice == 5) {
			int index_cmp;
			printf("Enter the index of the task\n");
			scanf("%d", &index_cmp);
			getchar();
			complete_task(index_cmp);
		} else {
			printf("Please choose from the given options\n");
			Sleep(2000);
		}
	}
	return 0;
}
void start_srceen()
{

	printf("CLI Todo application\n");
	printf("====================\n");
	printf("- to see all the tasks press 1\n");
	printf("- to see all the tasks by prio press 2\n");
	printf("- for a new task enter 3\n");
	printf("- to remove task press 4\n");
	printf("- to mark a task complete press 5\n");
	printf("- to close the program please press 0\n");

}

void see_tasks()
{
	printf("Num | Task\n");
	for (int i = 0; i < num_tasks; i++) {
		if (tasks[i].done) {
			printf("%d [x] - %s\n", i + 1, tasks[i].name);
		} else {
			printf("%d [ ] - %s\n", i + 1, tasks[i].name);
		}
	}
}
void tasks_prio()
{
    printf("Prio | Task\n");
	for (int i = 5; i > 0; i--) {
		for (int j = 0; j < num_tasks; j++ ) {
			if (tasks[j].prio == i)
				printf(" %d  -  %s\n", tasks[j].prio, tasks[j].name);
		}
	}
}
void new_task()
{
	printf("Enter the name of the task: \n");
	gets(&tasks[num_tasks].name);
	printf("Enter the priority of the task: \n");
	scanf("%d", &tasks[num_tasks].prio);
	getchar();
	tasks[num_tasks].done = 0;
	num_tasks++;
}
void rm_task(int index_task)
{
	num_tasks--;
	for (int i = index_task - 1; i < num_tasks; i++) {
		strcpy(tasks[i].name, tasks[i + 1].name);
		tasks[i].prio = tasks[i + 1].prio;
		tasks[i].done = tasks[i + 1].done;
	}
}
void complete_task(int index_cmp)
{
	tasks[index_cmp - 1].done = 1;
}
void clear_screen()
{
	system("cls");
}

