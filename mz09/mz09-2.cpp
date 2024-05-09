#include <iostream>
#include <string>
#include <vector>

std::pair<bool, std::string> extract_next(std::string &s, const std::vector<char> &alpha)
{
    std::string res;

    for (const char &c : alpha) {
        if (s[0] != c) {
            return std::make_pair(false, res);
        }
        
        size_t pos = s.find_first_not_of(c);

        if (pos == std::string::npos) {
            res += s;
            s = "";

            if (c != *--alpha.end()) {
                return std::make_pair(false, res);
            }

            return std::make_pair(true, res);
        }

        res += s.substr(0, pos);
        s.erase(0, pos);
    }

    return std::make_pair(true, res);
}

bool belongs(std::string &s, const std::vector<char> &alpha)
{
    std::pair<bool, std::string> begin = extract_next(s, alpha);

    if (!begin.first) {
        return false;
    }

    std::pair<bool, std::string> cur;

    while (s.length()) {
        cur = extract_next(s, alpha);

        if (!cur.first || begin.second != cur.second) {
            return false;
        }
    }

    return true;
}

int main()
{
    std::vector<char> alpha{ '0', '1' };
    std::string s;

    while (std::cin >> s) {
        std::cout << belongs(s, alpha) << std::endl;
    }

    return 0;
}
