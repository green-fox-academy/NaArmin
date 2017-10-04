#include <stdio.h>
#include <stdlib.h>

/*
Create a program which converts days to years, months, weeks and days
to keep it simple we say every year is 365 days long, every month is 30 days
*/

int main()
{
    int days = 3243;

    int year = days / 365;
    int month = (days - 365 * year) / 30;
    int week = (days - 365 * year - 30 * month) / 7;

    days = days - 365 * year - 30 * month - 7 * week;
    printf("%d", year);
    printf("%s\n", " Years");
    printf("%d", month);
    printf("%s\n", " Months");
    printf("%d", week);
    printf("%s\n", " Weeks");
    printf("%d", days);
    printf("%s\n", " Days");
    return 0;
}
