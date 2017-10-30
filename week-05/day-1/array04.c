#include <stdio.h>
#include <string.h>

int main(void)
{
    char first[] = "The ";
    char secnd[] = "Quick ";
    char third[] = "brown ";
    char fourth[] = "Dog ";
    char fifth[] = "jumps ";
    char sixth[] = "over ";
    char eighth[] = "the ";
    char ninth[] = "Lazy ";
    char tenth[] = "Fox.";

    char *ptrarray[9];
    ptrarray[0] = first;
    ptrarray[1] = secnd;
    ptrarray[2] = third;
    ptrarray[3] = fourth;
    ptrarray[4] = fifth;
    ptrarray[5] = sixth;
    ptrarray[6] = eighth;
    ptrarray[7] = ninth;
    ptrarray[8] = tenth;

    for (int i = 0; i < 9; i++)
        printf("%s\n", ptrarray[i]);
    strcpy(third, "Green");
    for (int i = 0; i < 3; i++)
        printf("%s\n", ptrarray[i]);
    printf("%s\n", ptrarray[8]);
    for (int i = 4; i < 8; i++)
        printf("%s\n", ptrarray[i]);
    printf("%s\n", ptrarray[3]);
    return 0;
}

