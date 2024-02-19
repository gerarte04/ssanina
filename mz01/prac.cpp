#include <iostream>
#include <stdlib.h>
#include <string.h>

// Cons Copy Cons Des Copy Des Des 1 Des

// ob.G() n X::Y::a f() X::a X::G(9) Z::a

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
};

int main()
{
    String s1, s2("qwerty"), s3 = s2, s4(100);

    return 0;
}
