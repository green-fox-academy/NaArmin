#include <stdio.h>
#include <string.h>

void func();
int main()
{
    //write a void function which asks for a number with scanf and print it out with printf, then
    //asks for a name with gets, and print it out with puts
    //you will notice something is wrong
    //try to solve the problem

    func();
    return 0;
}
void func()
{
    int num;
    char name[255];
    printf("Write a number, max. 9 digits please! ");
    if (scanf("%d", &num) == 1)
        printf("the given number is %d\n", num);
    gets(name); //reads out garbage
    printf("Write a name, please! ");
    gets(name);
    printf("the given name is: ");
    puts(name);
}

