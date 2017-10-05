#include <stdio.h>
#include <stdlib.h>

/*
Create a program which can tell how to pay an exact amount of money
for example 45670 Ft, is the amount (store this as an integer)
and the output should be:
2-20000Ft
1-5000Ft
1-500Ft
1-100Ft
1-50Ft
1-20Ft
*/

/*
Take care of the rounding (when giving back 5 coins):
1, 2 - 0 down
3, 4 - 5 up
6, 7 - 5 down
8, 9 - 0 up
*/

int main()
{
    int amount_of_money = 57545;
    int db;
    int cimlet;

    cimlet = 20000;
    db = amount_of_money / cimlet;
    if (db != 0) {
        amount_of_money -= db * cimlet;
        printf("%d - %d Ft\n", db, cimlet);
    }

    cimlet = 10000;
    db = amount_of_money / cimlet;
    if (db != 0) {
        amount_of_money -= db * cimlet;
        printf("%d - %d Ft\n", db, cimlet);
    }

    cimlet = 5000;
    db = amount_of_money / cimlet;
    if (db != 0) {
        amount_of_money -= db * cimlet;
        printf("%d - %d Ft\n", db, cimlet);
    }

    cimlet = 2000;
    db = amount_of_money / cimlet;
    if (db != 0) {
        amount_of_money -= db * cimlet;
        printf("%d - %d Ft\n", db, cimlet);
    }

    cimlet = 1000;
    db = amount_of_money / cimlet;
    if (db != 0) {
        amount_of_money -= db * cimlet;
        printf("%d - %d Ft\n", db, cimlet);
    }

    cimlet = 500;
    db = amount_of_money / cimlet;
    if (db != 0) {
        amount_of_money -= db * cimlet;
        printf("%d - %d Ft\n", db, cimlet);
    }

    cimlet = 200;
    db = amount_of_money / cimlet;
    if (db != 0) {
        amount_of_money -= db * cimlet;
        printf("%d - %d Ft\n", db, cimlet);
    }

    cimlet = 100;
    db = amount_of_money / cimlet;
    if (db != 0) {
        amount_of_money -= db * cimlet;
        printf("%d - %d Ft\n", db, cimlet);
    }

    cimlet = 50;
    db = amount_of_money / cimlet;
    if (db != 0) {
        amount_of_money -= db * cimlet;
        printf("%d - %d Ft\n", db, cimlet);
    }

    cimlet = 20;
    db = amount_of_money / cimlet;
    if (db != 0) {
        amount_of_money -= db * cimlet;
        printf("%d - %d Ft\n", db, cimlet);
    }

    cimlet = 10;
    db = amount_of_money / cimlet;
    if (amount_of_money > 7)
            db += 1;
    if (db != 0) {
        amount_of_money -= db * cimlet;
        printf("%d - %d Ft\n", db, cimlet);
    }

    cimlet = 5;
    if (amount_of_money >= 3) {
        db = 1;
        printf("%d - %d Ft\n", db, cimlet);
    }
    else {
        db = 0;
    }
    return 0;
}
