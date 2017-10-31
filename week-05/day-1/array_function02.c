#include <stdio.h>
#include <string.h>

int replacestr(char *big_s, char *small_s, int position);
void message(char *big_s, int stat);

int main(void)
{
    char arr1[] = "Quick brown dog";
    char arr2[] = "green fox";
    int status;
    status = replacestr(arr1, arr2, 7);
    message(arr1, status);
    status = replacestr(arr1, arr2, 16);
    message(arr1, status);
    status = replacestr(arr1, arr2, 8);
    message(arr1, status);
    return 0;
}
int replacestr(char *big_s, char *small_s, int position)
{
    if (position < 1 || position > strlen(big_s))
        return -1;
    if (position - 1 + strlen(small_s) > strlen(big_s))
        return 1;
    for (int i = 0; i < strlen(small_s); i++)
        big_s[position - 1 + i] = small_s[i];
    return 0;
}
void message(char *big_s, int stat)
{
    switch (stat) {
        case 0 :
            printf("New string is: %s\n", big_s);
            break;
        case -1 :
            printf("String out of bounds!\n");
            break;
        case 1 :
            printf("Insertion won't fit in original string!\n");
            break;
    }
    return;
}
