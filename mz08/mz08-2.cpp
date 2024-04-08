#include <exception>
#include <iostream>

class Result
{
    long res;
public:
    Result(long r) : res(r) { }
    long get() const { return res; }
};

void func(long a, long b, unsigned int k)
{
    if (k == 0) {
        throw Result(a + b);
    }
    if (b == 1) {
        throw Result(a);
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
