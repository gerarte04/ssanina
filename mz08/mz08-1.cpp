#include <exception>
#include <iostream>
#include <string>

class Printer
{
    std::string s{};
public:
    Printer()
    {
        if (!(std::cin >> s)) {
            throw std::exception();
        }
    }
    ~Printer()
    {
        std::cout << s << std::endl;
    }
};

void process()
{
    Printer p;
    process();
}

int main()
{
    try {
        process();
    }
    catch (const std::exception&) { }

    return 0;
}
