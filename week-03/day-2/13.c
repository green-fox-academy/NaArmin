#include <stdio.h>
#include <string.h>

int main ()
{
	char str[] = "This is a sample string";

	//TODO: write a program which prints out the distance between the first and last occurance of character 's'
	printf("The distance of first and last 's' is: %d", strrchr(str, 's') - strchr(str, 's') );
    return 0;
}

