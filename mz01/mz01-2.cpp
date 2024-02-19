#include <iostream>

class A
{
    int x;
    bool print;
public:
    A() : print(true) { std::cin >> x; }

    A(A &a)
    {
        std::cin >> x;
        x += a.x;
        a.unprint();
    }

    void unprint()
    {
        print = false;
    }

    ~A()
    {
        if (print) {
            std::cout << x << std::endl;
        }
    }
};
