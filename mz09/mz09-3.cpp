#include <iostream>
#include <string>

bool is_belong(const std::string &s)
{
    int cnt_a = 0, cnt_0 = 0;
    auto it = s.begin();

    for (; it != s.end() && *it == 'a'; ++it) {
        ++cnt_a;
    }

    for (; it != s.end() && *it == '0'; ++it) {
        ++cnt_0;
    }

    if (!cnt_a || !cnt_0) {
        return false;
    }

    int cnt_1 = 0, cnt_b = 0;

    for (; it != s.end() && *it == 'b'; ++it) {
        ++cnt_b;
    }

    for (; it != s.end() && *it == '1'; ++it) {
        ++cnt_1;
    }

    return it == s.end() && cnt_a == cnt_b && cnt_0 == cnt_1;
}

int main()
{
    std::string s;
    
    while (std::cin >> s) {
        std::cout << is_belong(s) << std::endl;
    }

    return 0;
}
