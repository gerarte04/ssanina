#include <algorithm>
#include <iostream>
#include <map>
#include <string>

class Gpa
{
    double mean = 0;
    int n = 0;
public:
    Gpa & operator+= (int x)
    {
        n++;
        mean += (x - mean) / n;
        return *this;
    }
    double get() const { return mean; }
};

int main()
{
    std::map<std::string, Gpa> gpas;
    std::string name;

    while (std::cin >> name) {
        int mark;
        std::cin >> mark;
        gpas[name] += mark;
    }

    for (auto it = gpas.begin(); it != gpas.end(); it++) {
        std::cout << it->first << ' ' << it->second.get() << std::endl;
    }

    return 0;
}
