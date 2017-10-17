#include <stdio.h>
#include <string.h>

int main()
{
    printf("Type in a sentence:\n\n");
    char string[256];

    //TODO: write a c program which, splits a string to words by space
	//solve the problem with the proper string.h function
	char *word;
    gets(string);
    word = strtok(string, " ");
    puts("-Sentence broken into words: ");
    while (word != NULL) {
        puts(word);
        word = strtok(NULL, " ");
    }
    return(0);
}

