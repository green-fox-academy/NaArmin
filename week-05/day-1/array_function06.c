#include <stdio.h>
#include <string.h>

int char_first_at(char *chars, char c);

int main(void)
{
    char input[] = "In the year 2525, If man is still alive... In the Year 3535, In the Year 4545";
    char to_find = 'u';

    if (char_first_at(input, to_find) != 0)
        printf("The first position of char %c is %d.", to_find, char_first_at(input, to_find));
    else
        printf("The char %c is not in string!", to_find);
    return 0;
}
int char_first_at(char *chars, char c)
{
    int *pos;
    pos = strcspn(chars, &c) + 1;
    if (pos == strlen(chars) + 1)
        pos = 0;
    return pos;
}

