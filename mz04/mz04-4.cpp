#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

class Eval
{
    double mean = 0;
    int n = 0;
public:
    Eval & operator() (double x)
    {
        n++;
        mean += (x - mean) / n;
        return *this;
    }
    double get() const { return mean; }
};

int main()
{
    static constexpr int PROP = 10;

    std::vector<double> v;
    double x;

    while (std::cin >> x) {
        v.push_back(x);
    }

    int away = v.size() / PROP;
    std::sort(v.begin() + away, v.end() - away);

    away += (v.size() - 2 * away) / PROP;
    Eval mean = std::for_each(v.begin() + away, v.end() - away, Eval());
    std::cout << std::fixed << std::showpoint << std::setprecision(10) << mean.get();

    return 0;
}
