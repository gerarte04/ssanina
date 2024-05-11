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

bool is_grammar(const std::vector<std::pair<std::string, std::string>> &rules)
{
    if (!rules.size()) {
        return false;
    }

    bool has_s = false;

    for (const auto &[l, r] : rules) {
        int cnt_nterm = 0;

        if (l.length() == 1 && l[0] == 'S') {
            has_s = true;
        }

        for (const char &c : l) {
            if (is_nterm(c)) {
                ++cnt_nterm;
            }
        }

        if (!cnt_nterm) {
            return false;
        }
    }

    return has_s;
}

bool is_context_free(const std::vector<std::pair<std::string, std::string>> &rules)
{
    for (const auto &[l, r] : rules) {
        if (l.length() > 1) {
            return false;
        }
    }

    return true;
}

bool is_not_shortening(const std::vector<std::pair<std::string, std::string>> &rules)
{
    bool has_eps_s = false;
    int cnt_s_right = 0;

    for (const auto &[l, r] : rules) {
        if (r[0] == '_') {
            if (l[0] == 'S') {
                has_eps_s = true;
            } else {
                return false;
            }
        }

        for (const char &c : r) {
            if (c == 'S') {
                ++cnt_s_right;
            }
        }
    }

    return !has_eps_s || (has_eps_s && !cnt_s_right);
}

int main()
{
    std::vector<std::pair<std::string, std::string>> rules;
    std::string l, r;

    while (std::cin >> l >> r) {
        rules.push_back(std::make_pair(l, r));
    }

    if (is_grammar(rules)) {
        if (is_context_free(rules)) {
            if (is_not_shortening(rules)) {
                std::cout << 23 << std::endl;
            } else {
                std::cout << 2 << std::endl;
            }
        } else {
            std::cout << 10 << std::endl;
        }
    } else {
        std::cout << -1 << std::endl;
    }

    return 0;
}
