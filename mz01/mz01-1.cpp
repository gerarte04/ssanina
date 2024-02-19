class Sum
{
    int a;
    int b;
public:
    Sum(int a, int b) : a(a), b(b) { }
    Sum(Sum s, int c) : a(s.get()), b(c) { }
    int get() const { return a + b; }
};
