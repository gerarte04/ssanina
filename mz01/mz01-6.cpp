#include <iomanip>
#include <iostream>

enum Status
{
    Parallel = 0,
    Crossing = 1,
    Equal = 2
};

struct CrossInfo
{
    Status st;
    double x_cr;
    double y_cr;
};

class Point
{
public:
    int x;
    int y;
    Point(int x, int y) : x(x), y(y) { }
};

class Line
{
public:
    double k;
    double b;
    bool is_vertical;
    double x_off;

    Line(const Point &, const Point &);
    CrossInfo get_cross_info(const Line &) const;
};

Line::Line(const Point &p1, const Point &p2)
{
    is_vertical = p1.x == p2.x;

    if (is_vertical) {
        x_off = p1.x;
    } else {
        k = ((p1.x > p2.x) ? (double) (p1.y - p2.y) / (p1.x - p2.x) : (double) (p2.y - p1.y) / (p2.x - p1.x));
        b = p1.y - p1.x * k;
    }
}

CrossInfo Line::get_cross_info(const Line &l1) const
{
    CrossInfo ci;

    if (is_vertical) {
        if (l1.is_vertical) {
            if (x_off == l1.x_off) {
                ci.st = Equal;
            } else {
                ci.st = Parallel;
            }

            return ci;
        } else {
            ci.st = Crossing;
            ci.x_cr = x_off;
            ci.y_cr = l1.k * x_off + l1.b;
            return ci;
        }
    } else if (l1.is_vertical) {
        ci.st = Crossing;
        ci.x_cr = l1.x_off;
        ci.y_cr = k * l1.x_off + b;
        return ci;
    } else if (k == l1.k) {
        if (b == l1.b) {
            ci.st = Equal;
        } else {
            ci.st = Parallel;
        }

        return ci;
    } else {
        ci.st = Crossing;
        ci.x_cr = (l1.b - b) / (k - l1.k);
        ci.y_cr = k * ci.x_cr + b;
        return ci;
    }
}

int main()
{
    int x1, y1;
    int x2, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    Line l1(Point(x1, y1), Point(x2, y2));
    std::cin >> x1 >> y1 >> x2 >> y2;
    Line l2(Point(x1, y1), Point(x2, y2));

    CrossInfo ci = l1.get_cross_info(l2);
    std::cout << ci.st << std::endl;

    if (ci.st == Crossing) {
        std::cout << std::fixed << std::showpoint << std::setprecision(5)
            << ci.x_cr << std::endl << ci.y_cr << std::endl;
    }

    return 0;
}
