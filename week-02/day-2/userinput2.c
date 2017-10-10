#include <stdio.h>

int main() {
    char buffer[255];   // Buffer variable for user input

    //TODO:
    // Get the user's name with gets
    puts("Your name is:");
    gets(buffer);

    //TODO:
    // Print it out with puts
    puts(buffer);
    //TODO:
    // Get the user's pet name with getch
    puts("Name of your pet:");
    int i = 0;
    char ch;
    do {
        ch = getchar();
        buffer[i] = ch;
        i++;
    } while (ch != 10); // ENTER key by code

    //TODO:
    // Print it out
    for (int j = 0; j < i; j++)
        putchar(buffer[j]);
    return 0;
}

