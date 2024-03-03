#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>

namespace numbers {
    class complex
    {
        double r;
        double i;
    public:
        complex(double x = 0.0, double y = 0.0) : r(x), i(y) { }
        explicit complex(std::string s)
        {
            int comma = s.find(',');
            r = std::stod(s.substr(1, comma - 1));
            i = std::stod(s.substr(comma + 1, s.size() - comma - 2));
        }
        double re() const { return r; }
        double im() const { return i; }
        double abs2() const { return r * r + i * i; }
        double abs() const { return sqrt(abs2()); }
        std::string to_string() const {
            std::ostringstream stream1, stream2;
            stream1 << std::fixed << std::showpoint << std::setprecision(10) << r;
            stream2 << std::fixed << std::showpoint << std::setprecision(10) << i;
            return "(" + stream1.str() + "," + stream2.str() + ")";
        }
        complex & operator+= (const complex &a)
        {
            r += a.r;
            i += a.i;
            return *this;
        }
        complex & operator-= (const complex &a)
        {
            r -= a.r;
            i -= a.i;
            return *this;
        }
        complex & operator*= (const complex &a)
        {
            r = r * a.r - i * a.i;
            i = r * a.i + i * a.r;
            return *this;
        }
        complex & operator/= (const complex &a)
        {
            r = (r * a.r + i * a.i) / a.abs2();
            i = (i * a.r - r * a.i) / a.abs2();
            return *this;
        }
        friend complex operator+ (const complex &a, const complex &b)
        {
            complex c(a.re(), a.im());
            c += b;
            return c;
        }
        friend complex operator- (const complex &a, const complex &b)
        {
            complex c(a.re(), a.im());
            c -= b;
            return c;
        }
        friend complex operator* (const complex &a, const complex &b)
        {
            complex c(a.re(), a.im());
            c *= b;
            return c;
        }
        friend complex operator/ (const complex &a, const complex &b)
        {
            complex c(a.re(), a.im());
            c += b;
            return c;
        }
        complex operator- () const { return complex(-r, -i); }
        complex operator~ () const { return complex(r, -i); }
        complex & operator= (const complex &obj)
        {
            r = obj.r;
            i = obj.i;
            return *this;
        }   
    };
}
