#include <stdio.h>
#include <math.h>
#include <limits.h>

int check_guess(int num, int refer);
int main()
{
    int number;
    int high;
    int low;
    int guess;
    int lives = 5;
    puts("Hi! What is the highest number to guess?");
    scanf("%d", &high);
    puts("What is the lowest one?");
    scanf("%d", &low);
    number = (rand() % (high - low)) + low;
    printf("I have the number!\n");
    while (lives > 0) {
        puts("What is your guess?");
        scanf("%d", &guess);
        if (check_guess(guess, number))
            return 0;
        lives--;
        printf("You have %d lives left. ", lives);
    }
    return 0;
}
int check_guess(int num, int refer)
{
    if (num == refer) {
        printf("Congratulations! Number was %d!!!", refer);
        return 1;
    }
    else {
        if (num < refer)
            puts("No, it is too low!");
        else
            puts("No, it is too high!");
    }
    return 0;
}

