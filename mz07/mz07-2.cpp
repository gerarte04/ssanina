#include <math.h>
#include <sstream>
#include <string>

class Rectangle : public Figure
{
    double a{}, b{};
public:
    Rectangle(double a, double b) : a(a), b(b) { }
    static Rectangle* make(const std::string &s)
    {
        double a = 0, b = 0;
        std::istringstream iss(s);
        iss >> a >> b;
        return new Rectangle(a, b);
    }
    double get_square() const override
    {
        return a * b;
    }
};

class Square : public Figure
{
    double a{};
public:
    Square(double a) : a(a) { }
    static Square* make(const std::string &s)
    {
        return new Square(std::stod(s));
    }
    double get_square() const override
    {
        return a * a;
    }
};

class Circle : public Figure
{
    double r{};
public:
    Circle(double r) : r(r) { }
    static Circle* make(const std::string &s)
    {
        return new Circle(std::stod(s));
    }
    double get_square() const override
    {
        return M_PI * r * r;
    }
};
