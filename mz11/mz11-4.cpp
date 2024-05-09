class Figure
{
public:
    virtual bool equals(const Figure*) const = 0;
    virtual ~Figure() { }
};

class Rectangle : public Figure
{
    int a{}, b{};
public:
    Rectangle(int a, int b) : a(a), b(b) { }
    bool equals(const Figure *f) const override
    {
        const Rectangle *r = dynamic_cast<const Rectangle*>(f);
        return r && r != nullptr && a == r->a && b == r->b;
    }
};

class Triangle : public Figure
{
    int a{}, b{}, c{};
public:
    Triangle(int a, int b, int c) : a(a), b(b), c(c) { }
    bool equals(const Figure *f) const override
    {
        const Triangle *t = dynamic_cast<const Triangle*>(f);
        return t && t != nullptr && a == t->a && b == t->b && c == t->c;
    }
};
