#include <stdio.h>

int my_strlen(char *string);

int main()
{
	char my_string[50] = "Hello world!";

	//TODO: implement your own strlen function.
    printf("%s ---length: %d", my_string, my_strlen(&my_string));
	return 0;
}
int my_strlen(char *string)
{
    int reallength = 0;
    char *p = &string[0];
    while (*p) {
        reallength++;
        p++;
    }
    return reallength;
}

