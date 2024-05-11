#include <iostream>
#include <string>
#include <vector>

bool is_term(char c)
{
    return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

bool is_nterm(char c)
{
    return c >= 'A' && c <= 'Z';
}

bool is_left(const std::string &s)
{
    if (s.length() == 1 && s[0] == '_') {
        return true;
    }

    for (auto it = s.begin() + 1; it != s.end(); ++it) {
        if (is_nterm(*it)) {
            return false;
        }
    }

    return true;
}

bool is_right(const std::string &s)
{
    if (s.length() == 1 && s[0] == '_') {
        return true;
    }

    auto last = s.end() - 1;

    for (auto it = s.begin(); it != last; ++it) {
        if (is_nterm(*it)) {
            return false;
        }
    }

    return true;
}

bool is_left_regular(const std::vector<std::pair<std::string, std::string>> &rules)
{
    for (const auto &[l, r] : rules) {
        if (!is_left(r)) {
            return false;
        }
    }

    return true;
}

bool is_right_regular(const std::vector<std::pair<std::string, std::string>> &rules)
{
    for (const auto &[l, r] : rules) {
        if (!is_right(r)) {
            return false;
        }
    }

    return true;
}

bool is_automatic(const std::vector<std::pair<std::string, std::string>> &rules)
{
    bool has_ext_right = false;
    int cnt_s_right = 0;

    for (const auto &[l, r] : rules) {
        if (l[0] == 'S' && r.length() == 1 && (r[0] == '_' || r[0] == 'A')) {
            has_ext_right = true;
        } else {
            int cnt_term = 0;
            
            for (const char &c : r) {
                cnt_term += is_term(c);

                if (c == 'S') {
                    ++cnt_s_right;
                }
            }

            if (cnt_term != 1) {
                return false;
            }
        }
    }

    return !has_ext_right || (has_ext_right && !cnt_s_right);
}

bool is_not_shortening(const std::vector<std::pair<std::string, std::string>> &rules)
{
    for (const auto &[l, r] : rules) {
        if (r[0] == '_') {
            return false;
        }
    }

    return true;
}

int main()
{
    std::vector<std::pair<std::string, std::string>> rules;
    std::string l, r;

    while (std::cin >> l >> r) {
        rules.push_back(std::make_pair(l, r));
    }

    if (is_left_regular(rules)) {
        if (is_automatic(rules)) {
            std::cout << 311 << std::endl;
        } else {
            std::cout << 31 << std::endl;
        }
    } else if (is_right_regular(rules)) {
        if (is_automatic(rules)) {
            std::cout << 321 << std::endl;
        } else {
            std::cout << 32 << std::endl;
        }
    } else if (is_not_shortening(rules)) {
        std::cout << 21 << std::endl;
    } else {
        std::cout << 2 << std::endl;
    }

    return 0;
}
