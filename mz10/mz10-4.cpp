#include <iostream>
#include <map>
#include <string>

std::pair<std::string::iterator, int> check_exp(std::string &s, std::string::iterator cur)
{
    static constexpr int MAX_PR = 6;
    static std::map<char, int> prs = {
        {'*', 1}, {'/', 1},
        {'+', 2}, {'-', 2},
        {'&', 3},
        {'^', 4},
        {'|', 5}
    };

    int prev = MAX_PR;
    int lowest = 0;

    for (; *cur != ')' && cur != s.end(); ++cur) {
        if (*cur == '(') {
            auto begin_off = std::distance(s.begin(), cur);
            auto [end, inner_lw] = check_exp(s, cur + 1);

            int next = MAX_PR;
            ++end;

            if (end != s.end() && prs.find(*end) != prs.end()) {
                next = prs[*end];
            }

            if (inner_lw < prev && inner_lw <= next) {
                auto end_off = std::distance(s.begin(), end) - 1;
                s.erase(end - 1);
                s.erase(begin_off, 1);
                cur = s.begin() + end_off - 2;
                lowest = (inner_lw > lowest) ? inner_lw : lowest;
            } else {
                cur = end - 1;
            }
        } else if (prs.find(*cur) != prs.end()) {
            prev = prs[*cur];
            lowest = (prs[*cur] > lowest) ? prs[*cur] : lowest;
        }
    }

    return std::make_pair(cur, lowest);
}

int main()
{
    std::string input;
    std::cin >> input;
    
    check_exp(input, input.begin());
    std::cout << input << std::endl;

    return 0;
}
