class Sum
{
    int a;
    int b;
public:
    Sum(int a, int b) : a(a), b(b) { }
    Sum(Sum s, int c) : a(s.get()), b(c) { }
    Sum(int a, Sum s) : a(a), b(s.get()) { }
    int get() const { return a + b; }
};
