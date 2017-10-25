#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int x;
    int y;
} point_t;

// TODO:
// Create a function the constructs a point
// It should take it's x and y coordinate as parameter
void createpoint(int x, int y, point_t *p);
// TODO:
// Create a function that takes 2 Points as a pointer and returns the distance between them
float distancepoints(point_t *a, point_t *b);

int main()
{
    int px;
    int py;
    point_t *point1;
    point_t *point2;
    printf("please enter point 1 x: ");
    scanf("%d", &px);
    printf("please enter point 1 y: ");
    scanf("%d", &py);
    createpoint(px, py, &point1);
    printf("please enter point 2 x: ");
    scanf("%d", &px);
    printf("please enter point 2 y: ");
    scanf("%d", &py);
    createpoint(px, py, &point2);
    printf("\nDistance of the points is %.2f.", distancepoints(&point1, &point2));
    return 0;
}
void createpoint(int x, int y, point_t *p)
{
    p->x = x;
    p->y = y;
}
float distancepoints(point_t *a, point_t *b)
{
    double dx = a->x - b->x;
    double dy = a->y - b->y; printf("...%d...%d...%d...%d", a->x, a->y, b->x, b->y);
    return sqrt((dx * dx) + (dy * dy));
}

