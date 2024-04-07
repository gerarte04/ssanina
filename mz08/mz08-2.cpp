#include <exception>
#include <iostream>

class Result
{
    long res;
public:
    Result(long r) : res(r) { throw *this; }
    long get() const { return res; }
};

void func(long a, long b, unsigned int k)
{
    if (k == 0) {
        Result res(a + b);
    }
    if (b == 1) {
        Result res(a);
    }

    try {
        func(a, b - 1, k);
    }
    catch (const Result &res) {
        func(a, res.get(), k - 1);
    }
}

int main()
{
    long a, b;
    unsigned int k;

    while (std::cin >> a >> b >> k) {
        try {
            func(a, b, k);
        }
        catch (const Result &res) {
            std::cout << res.get() << std::endl;
        }
    }

    return 0;
}
