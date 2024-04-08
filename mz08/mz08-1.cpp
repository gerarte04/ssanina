#include <exception>
#include <iostream>
#include <string>

class Printer
{
    std::string s{};
public:
    Printer(const std::string &s) : s(s) { }
    ~Printer()
    {
        std::cout << s << std::endl;
    }
};

void process()
{
    std::string s;

    if (!(std::cin >> s)) {
        throw std::exception();
    }

    Printer p(s);
    process();
}

int main()
{
    try {
        process();
    } catch (const std::exception&) { }

    return 0;
}
