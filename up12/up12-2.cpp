#include <iostream>
#include <string>

/*
S -> 1S0 | 1A0
A -> 01 | 0A1
*/

char c;

void A(std::string::iterator &it)
{
    std::cout << '1';
    ++it;
    if (*it == '0') {
        A(it);
    }
    std::cout << '0';
    ++it;
}

void S(std::string::iterator &it)
{
    ++it;
    if (*it == '1') { S(it); }
    else if (*it == '0') { A(it); }
    std::cout << '0';
}

int main()
{
    std::string s;
    
    while (std::cin >> s) {
        auto it = s.begin();
        S(it);
        std::cout << std::endl;
    }
}
