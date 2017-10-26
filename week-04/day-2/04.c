#include <stdio.h>

struct rectangular_cuboid {
    double a;
    double b;
    double c;
};

// TODO:
// Write a function called "GetSurface" that takes a RectangularCuboid
// and returns it's surface
double GetSurface(struct rectangular_cuboid inputcub);
// TODO:
// Write a function called "GetVolume" that takes a RectangularCuboid
// and returns it's volume
double GetVolume(struct rectangular_cuboid inputcub);

int main()
{
    struct rectangular_cuboid box;
    box.a = 0.02;
    box.b = 0.02;
    box.c = 0.02;
    printf("The surface of cuboid is %G\nthe volume of it is %G.", GetSurface(box), GetVolume(box));
    return 0;
}
double GetSurface(struct rectangular_cuboid inputcub)
{
    double s1, s2, s3;
    s1 = inputcub.a * inputcub.b;
    s2 = inputcub.b * inputcub.c;
    s3 = inputcub.c * inputcub.a;
    return 2 * s1 + 2 * s2 + 2 * s3;
}
double GetVolume(struct rectangular_cuboid inputcub)
{
    return inputcub.a * inputcub.b * inputcub.c;
}

