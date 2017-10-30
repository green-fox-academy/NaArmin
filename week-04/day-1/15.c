#include <stdio.h>
#include <string.h>

void reverse_name(char *name, char *reversed_name);

int main(void)
{
	char name[] = "Gipsz Jakab";

    char reversed[50];

    //write a function which reverse a name's last name and first name. Use a void function. Put your 'return' value in the second parameter.
    reverse_name(&name, &reversed);
    printf("%s reversed: %s", name, reversed);
}
void reverse_name(char *name, char *reversed_name)
{
    char name2[50];
    strcpy(name2, name);
    strcpy(name2, strtok(name2, " "));
    strcpy(reversed_name, strtok(NULL, " "));
    strcat(reversed_name, " ");
    strcat(reversed_name, strtok(name2, " "));
    return;
}

