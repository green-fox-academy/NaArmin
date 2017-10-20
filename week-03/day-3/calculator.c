#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "strhandlers.h"
#include "calculate.h"

void helpscreen();
void examine_ops(void);
void set_cursor_pos(int x, int y);
COORD coord = {0,0};
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
            examine_ops();
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
    puts("+	summation");
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
    *firstnum = *operat = *secondnum = NULL;
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
void examine_ops(void)
{
    char op;
    op = operat[0];
    float r = strtof(&firstnum, NULL);
    float n = strtof(&secondnum, NULL);
    float a = strtof(&firstnum, NULL);
    float b = strtof(&secondnum, NULL);
    long nb = strtol(&firstnum, NULL, 2);
    long nd = strtol(&firstnum, NULL, 10);
    long nh = strtol(&firstnum, NULL, 16);
    switch (op) {
    case '+':
        printf(" = %f\n", strtof(&firstnum, NULL) + strtof(&secondnum, NULL));
        break;
    case '-':
        printf(" = %f\n", strtof(&firstnum, NULL) - strtof(&secondnum, NULL));
        break;
    case '*':
        printf(" = %f\n", strtof(&firstnum, NULL) * strtof(&secondnum, NULL));
        break;
    case '/':
        printf(" = %f\n", strtof(&firstnum, NULL) / strtof(&secondnum, NULL));
        break;
    case '%':
        printf(" = %d\n", (int)strtof(&firstnum, NULL) % (int)strtof(&secondnum, NULL));
        break;
    case '^':
        printf(" = %f\n", pow(n, r));
        break;
    case '<':
        if (r != 0)
            printf(" = %f\n", pow(n, 1 / r));
        break;
    case 'l':
        if (!strcmp(operat, "log"))
            if (a != 0)
                printf(" = %f\n", log10(b) / log10(a));
        break;
    case 'b':
        if (!strcmp(operat, "binto")) {
            char out[65];
            itoa(nb, out, atoi(&secondnum));
            printf(" = %s\n", out);
        }
        break;
    case 'd':
        if (!strcmp(operat, "decto")) {
            char out[65];
            itoa(nd, out, atoi(&secondnum));
            printf(" = %s\n", out);
        }
        break;
    case 'h':
        if (!strcmp(operat, "hexto")) {
            char out[65];
            itoa(nh, out, atoi(&secondnum));
            printf(" = %s\n", out);
        }
        break;
    default:
        puts("Operator can not be recognized!");
        break;
    }
}
void set_cursor_pos(int x, int y)
{
    printf("\033[%d;%dH", y+1, x+1);
	coord.X = x;
	coord.Y = y;
	//SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
