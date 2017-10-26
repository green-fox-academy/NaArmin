#include <stdio.h>

// TODO:
// Create a struct that represents a House
// It should store:
//  - The address of the house
//  - The price in EUR
//  - The number of rooms
//  - The area of the house in square meters
struct HOUSE {
    char *address;
    unsigned int price;
    float rooms;
    unsigned int area;
    };
// TODO:
// The market price of the houses is 400 EUR / square meters
// Create a function that takes a pointer to a house and decides if it's worth to buy
// (if the price is lower than the calculated price from it's area)
int worthbuying(struct HOUSE *h);
// TODO:
// Create a function that takes an array of houses (and it's length), and counts the
// houses that are worth to buy.
int worthbuy_count(struct HOUSE houses[], int num);

int main() {
    struct HOUSE h1;
    h1.address = "Addr 1";
    h1.area = 43;
    h1.price = 17990;
    h1.rooms = 1.5;
    struct HOUSE h2;
    h2.address = "Addr 2";
    h2.area = 90;
    h2.price = 20900;
    h2.rooms = 3;
    struct HOUSE h3;
    h3.address = "Addr 2";
    h3.area = 70;
    h3.price = 18900;
    h3.rooms = 2;

    struct HOUSE town1[3];
    town1[0] = h1;
    town1[1] = h2;
    town1[2] = h3;
    printf("Houses worth to buy: %d", worthbuy_count(town1, sizeof(town1) / sizeof(town1[0])));
    return 0;
}
int worthbuying(struct HOUSE *h)
{
    float sqm_pr = h->price / h->area;
    if (sqm_pr < 400)
        return 1;
    else
        return 0;
}
int worthbuy_count(struct HOUSE houses[], int num)
{
    int wbcount = 0;
    for (int i = 0; i < num; i++)
        if (worthbuying(&houses[i]))
            wbcount++;
    return wbcount;
}

