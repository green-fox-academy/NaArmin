#ifndef CIRCLE_H
#define CIRCLE_H


class Circle
{
    public:
        Circle(float);
        float get_circumference();
        float get_area();
        ~Circle();
    private:
        float radius;
};

#endif // CIRCLE_H
