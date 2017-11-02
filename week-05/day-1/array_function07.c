#include <stdio.h>
#include <string.h>

int *char_at(char *chars, char c);

int main(void)
{
    int *indexes;
    char input[] = "Where is my cat? He?";
    char to_find = 'e';

    if (char_at(input, to_find)[0] != 0) {
        indexes = char_at(input, to_find);
        for (int i = 1; i < indexes[0] + 1; i++)
            printf(" %d ", indexes[i]);
    } else {
        printf("The char %c is not in string!", to_find);
    }
    return 0;
}
int *char_at(char *chars, char c)
{
    char *pos;
    static int positions[100];
    int index = 1;
    positions[0] = 0;
    pos = strchr(chars, c);
    while (pos != NULL) {
        positions[index] = pos - chars;
        pos++;
        index++;
        positions[0] += 1;
        pos = strchr(pos, c);
    }

    return positions;
}

