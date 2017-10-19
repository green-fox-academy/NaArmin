#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void helpscreen();
int split_input(char *input);
char firstnum[30], operat[10], secondnum[30];

int main(void)
{
    char input[100];
    int iscommand = 0;
    helpscreen();
    while (1) {
        gets(input);
        if (strstr(strlwr(input), "help")) {
            iscommand = 1;
            helpscreen();
        }
        if (strstr(strlwr(input), "clear")) {
            iscommand = 1;
            system("cls");
            system("clear");
        }
        if (strstr(strlwr(input), "exit"))
            break;
        if (!iscommand) {
            if (split_input(input))
                puts("You have omitted one or more spaces!");
        }
        iscommand = 0;
    }
    puts("Good Bye!");
    return 0;
}
void helpscreen()
{
    puts("         CLI Calculator");
    puts("====================================");
    puts("usage: [number] [operation] [number]");
    puts("Commands:\n");
    puts(" +	summation");
    puts("-	subtraction");
    puts("*	multiplication");
    puts("/	division");
    puts("%	division with remainder");
    puts("^	squaring");
    puts("<	square root");
    puts("log	logarithm");
    puts("binto	binary to hex or dec");
    puts("hexto	hexadecimal to bin or dec");
    puts("decto	decimal to bin or hex");
    puts("====================================");
    puts("exit	exiting from the program");
    puts("clear	clear the screen");
    puts("help	print usage");
    puts("====================================");
    printf("Hit enter to start!");
    char wait;
    gets(&wait);
}
int split_input(char *input)
{
    char *t, *u, *v;
    t = strtok(input, " ");
    u = strtok(NULL, " ");
    v = strtok(NULL, " ");
    if (t == NULL || u == NULL || v == NULL)
        return 1;
    strcpy(firstnum, t);
    strcpy(operat, u);
    strcpy(secondnum, v);
    return 0;
}
