#include <stdio.h>

int josephus(int places);
int main()
{
    int people;
    puts("How many people are standing in the circle?");
    scanf("%d", &people);
    printf("The survival place is %d.", josephus(people));
    return 0;
}
int josephus(int places)
{
    int survive = 0;
    int remain = places;
    int circle[places - 1];
    int cntr = 0;
    for (int i = 0; i < places; i++)
        circle[i] = 1;
    while (remain > 1) {
        if (survive >= places)
            survive = survive - places;
        if (circle[survive] == 1 && cntr == 0) {
            circle[survive] = 0;
            remain--;
            cntr = 1;
            printf("%d ", survive);
        }
        else {
            cntr = 0;
        }

        survive++;
    }
    return survive + 1;
}

