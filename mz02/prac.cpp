#include <iostream>
#include <string.h>

class C
{
    double re;
    double im;
public:
    C(double x = 0.0, double y = 0.0) : re(x), im(0) { }
    bool operator== (const C &obj) const { return re == obj.re && im == obj.im; }
    friend C operator+ (const C &a, const C &b) { return C(a.re + b.re, a.im + b.im); }
    C operator- () const { return C(-re, -im); }
    C & operator++ () { ++re; return *this; } // prefix
    C operator++ (int not_used) // postfix
    {
        C tmp(re, im);
        re++;
        return tmp;
    }
    C & operator= (const C &obj)
    {
        re = obj.re;
        im = obj.im;
        return *this;
    }
};

class String
{
    char *str;
    int len;
public:
    String(int n = 1)
    {
        len = n;
        str = new char[len];
        str[0] = '\0';
    }
    String(const char *cpy)
    {
        len = strlen(cpy) + 1;
        str = new char[len];
        strncpy(str, cpy, len);
    }
    String(const String &s)
    {
        len = s.len;
        str = new char[s.len];
        strncpy(str, s.str, s.len);
    }
    String(String &&v)
    {
        str = v.str;
        len = v.len;
        v.str = nullptr;
    }
    ~String()
    {
        delete[] str;
    }
    char & operator[](int i) { return str[i]; }
    String & operator= (const String &s)
    {
        if (this == &s) {
            return *this;
        }

        len = s.len;
        delete[] str;
        str = new char[len];
        strncpy(str, s.str, len);
        return *this;
    }
    String operator+ (const String &s)
    {
        String newstr(len + s.len - 1);
        strncpy(newstr.str, str, len - 1);
        strcat(newstr.str, s.str);
        return newstr;
    }
    friend std::istream & operator>> (std::istream &stream, String &s) // incorrect
    {
        char str[];
        stream >> str;
        s.len = strlen(str) + 1;
        s.str = new char[s.len];
        strncpy(s.str, str, s.len);

        return stream;
    }
    friend std::ostream & operator<< (std::ostream &stream, const String &s)
    {
        stream << s.str;
        return stream;
    }
    void swap(String &a)
    {
        std::swap(str, a.str);
        std::swap(len, a.len);
    }
};

class Pred
{
    bool operator() (int v) { return v < 10; }
}

void f(int *m, int n, Pred c)
{
    for (int i = 0; i < n; i++) {
        if (c(m[i])) {
            m[i] *= 2;
        }
    }
}

int main()
{
    // C c1(1, 2), c2(1), c3;

    // if (c1 == c2) {
    //     std::cout << "equal" << std::endl;
    // }

    // C a(1, 2), b;
    // b = -a;
    // b = ++a;

    // String s1("abcd"), s2("klm"), s3;
    // s2[1] = 'A';
    // s3 = s1 + s2;
    // std::cout << s3 << std::endl;

    String s;
    std::cin >> s;
    std::cout << s << std::endl;
}
