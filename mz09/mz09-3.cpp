#include <iostream>
#include <string>

/*
S -> aSb | a0A1b
A -> 0A1 | 01
1b -> b1
*/

// параша, какую поискать надо

bool is_belong(const std::string &s)
{
    int cnt_a = 0, cnt_0 = 0;
    auto it = s.begin();

    for (; *it == 'a'; ++it) {
        ++cnt_a;
    }

    for (; *it == '0'; ++it) {
        ++cnt_0;
    }

    if (!cnt_a || cnt_0 <= 1) {
        return false;
    }

    int cnt_1 = 0, cnt_b = 0;

    for (; it != s.end(); ++it) {
        if (*it == '1') {
            ++cnt_1;
        } else if (*it == 'b') {
            ++cnt_b;
        } else {
            return false;
        }
    }

    return cnt_a == cnt_b && cnt_0 == cnt_1;
}

int main()
{
    std::string s;
    
    while (std::cin >> s) {
        std::cout << is_belong(s) << std::endl;
    }

    return 0;
}
