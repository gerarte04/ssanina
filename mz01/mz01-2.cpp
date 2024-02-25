#include <iostream>

class A
{
    int x;
    bool print{};
public:
    A() { std::cin >> x; }

    A(const A &a)
    {
        std::cin >> x;
        x += a.x;
        print = true;
    }

    ~A()
    {
        if (print) {
            std::cout << x << std::endl;
        }
    }
};
