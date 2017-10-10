#include <stdio.h>

int main() {
    char buffer[255];   // Buffer variable for user input

    //TODO:
    // Get the user's name with scanf
    printf("Hi, what`s your name?\n");
    scanf("%s", buffer);

    //TODO:
    // Print it out with printf
    printf("Hello %s", buffer);
    return 0;
}

