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
    point_t point1, point2;
    point_t *pptr1, *pptr2;

    pptr1 = &point1;
    pptr2 = &point2;
    printf("please enter point 1 x: ");
    scanf("%d", &px);
    printf("please enter point 1 y: ");
    scanf("%d", &py);
    createpoint(px, py, pptr1);
    printf("please enter point 2 x: ");
    scanf("%d", &px);
    printf("please enter point 2 y: ");
    scanf("%d", &py);
    createpoint(px, py, pptr2);
    printf("\nDistance of the points is %.2f.", distancepoints(pptr1, pptr2));
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
    double dy = a->y - b->y;
    return sqrt((dx * dx) + (dy * dy));
}
