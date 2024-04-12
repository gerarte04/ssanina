#include <assert.h>

// хуйня

class Figure
{
public:
    virtual bool equals(Figure*) const = 0;
    virtual ~Figure() { }
};

class Rectangle : public Figure
{
    int a{}, b{};
public:
    Rectangle(int a, int b) : a(a), b(b) { }
    bool equals(Figure *f) const override
    {
        Rectangle *r = dynamic_cast<Rectangle*>(f);
        return r && a == r->a && b == r->b;
    }
};

class Triangle : public Figure
{
    int a{}, b{}, c{};
public:
    Triangle(int a, int b, int c) : a(a), b(b), c(c) { }
    bool equals(Figure *f) const override
    {
        Triangle *t = dynamic_cast<Triangle*>(f);
        return t && a == t->a && b == t->b && c == t->c;
    }
};

int main()
{
    Rectangle r1(1, 2), r2(10, 2), r3(10, 5), r4(5, 10);
    Triangle t1(1, 2, 3), t2(1, 2, 3);
    Figure *f = &r2;
    Figure *f1 = dynamic_cast<Figure*>(&r3);

    assert(f->equals(f1));
}
