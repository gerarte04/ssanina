#include <iostream>

class Point
{
    double x;
    double y;
public:
    Point(double x, double y) : x(x), y(y) { }
};

class Line
{
    double k;
    double b;
    bool is_vertical;
    double x_off;
public:
    Line(Point p1, Point p2)
    {
        is_vertical = p1.x == p2.x;

        if (is_vertical) {
            x_off = p1.x;
        } else {
            k = ((p1.x > p2.x) ? (p1.y - p2.y) / (p1.x - p2.x) : (p2.y - p1.y) / (p2.x - p1.x));
            b = p1.y - p1.x * k;
        }
    }
}
