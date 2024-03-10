class C {
    int n;
public:
    C(int k) : n(k * 2) { }
    friend int operator+ (const C &c1, const C &c2) { return c1.n + c2.n; }
    int get() const { return n; }
};
