#include <stdio.h>
#include <string.h>

int *birthy_extract(char *chars);

int main(void)
{
    char input[] = "2319834571976548721b1992456t831977451963782";
    int *birthdates;

    birthdates = birthy_extract(input);
    for (int i = 1; i <= birthdates[0]; i++)
        printf("%d\n", birthdates[i]);
    return 0;
}
int *birthy_extract(char *chars)
{
    static int years[100];
    char year[4];
    int value;
    years[0] = 0;
    for (int i = 0; i < strlen(chars) - 3; i++) {
        for (int x = 0; x < 4; x++)
            year[x] = chars[i + x];
        value = atoi(year);
        if (value >= 1900 && value < 2200) {
            years[0]++;
            years[years[0]] = value;
        }
    }
    return years;
}

