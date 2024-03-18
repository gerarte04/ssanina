#include <vector>
#include <list>
#include <iostream>
#include <functional>
#include <algorithm>

template <class T>

typename T::value_type sum(T &s)
{
    typename T::value_type sum{};
    typename T::const_iterator it = s.end();

    for (int i = 0; i < 5 && it != s.begin(); i++) {
        it--;
        sum += *it;
    }

    return sum;
}

template <class T>

class Check
{
    T &a;
    void
}

template <class T>

void apply(T a, T b, std::function<bool(typename T::value_type)> func, typename T::value_type val)
{
    std::for_each(a, b, [](typename T::value_type &x) {
        if (func(x)) {
            x = val;
        }
    });
}

int main()
{
    std::vector<int> v = { 100, 200, 0, 300, 500, 600 };
    std::list<double> l = { 4.5, 99, 5.6, 6.7, 1, 8, 0.5 };
    std::cout << sum(v) << std::endl;
    std::cout << sum(l) << std::endl;
}
