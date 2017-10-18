#include <stdio.h>
#include <string.h>
int main ()
{
	char string[55] ="This is a string for testing";
	char *p;
    char *x;
	//TODO: write a program, which lists all position where character 'i' is found
	x = strpbrk(string, &string[0]);
	p = strpbrk(string, "i");
	printf("Positions of i in \"%s\": ", string);
	while (p != NULL) {
        printf("%d., ", p - x + 1);
        p = strpbrk(p + 1, "i");
	}
	return 0;
}

