class C
{
public:
    C() {}
    C(double d) { }
    C(const C *v) { }
    C(const C &v1, int v2) { }
    int operator~ () const { return 1; }
    C & operator++ () { return *this; }
    int operator* (const C *v) const { return 1; }
    friend C operator+ (int v2, const C &v1) { return v1; }
};
