#include <iostream>
#include <string.h>

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
    
    class complex_stack
    {
        struct complex_elem
        {
            complex elem;
            complex_elem *next;
        }
        
        size_t sz = 0;
        complex_elem *st;
    public:
        complex_stack() { }
        ~complex_stack() { delete[] st; }
        size_t size() const { return sz; }
        const complex & operator[] (int i) const
        {
            complex *elem = st;

            for (; i > 0; i--) {
                elem = elem->next;
            }
        }
        friend complex_stack & operator<< (complex_stack &cs, const complex &a)
        {
            if (cs.sz == cs.cap) {
                cs.cap *= 2;
                complex *new_st = new complex[cs.cap];
                memmove(new_st, cs.st, cs.sz * sizeof(cs.st[0]));
                delete[] cs.st;
                cs.st = new_st;
            }

            cs.st[cs.sz] = a;
            cs.sz++;
        }
        complex_stack & operator+ ()
        {
            
        }
    };
}