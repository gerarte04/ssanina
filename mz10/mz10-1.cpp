#include <iostream>
#include <string>
#include <utility>

// хуйня

bool is_term(char c)
{
    return !(c >= 'A' && c <= 'Z');
}

bool is_eps(std::string s)
{
    return s.length() == 1 && s[0] == '_';
}

std::pair<bool, bool> check_left(std::string l, std::string r)
{
    if (l.length() != 1 || is_term(l[0])) {
        return std::make_pair(false, false);
    } else if (l[0] == 'S' && r.length() == 1 && !is_eps(r)) {
        if (r[0] == 'A') {
            return std::make_pair(true, true);
        }

        return std::make_pair(true, false);
    } else if (is_term(r[0])) {
        if (is_eps(r)) {
            if (l[0] == 'S') {
                return std::make_pair(true, true);
            }

            return std::make_pair(true, false);
        }

        if (r.length() == 1) {
            return std::make_pair(true, true);
        }
    } else if (r.length() == 1) {
        if (is_term(r[0])) {
            return std::make_pair(true, true);
        }

        return std::make_pair(false, false);
    }

    for (int i = 1; i < (int) r.length(); i++) {
        if (!is_term(r[i])) {
            return std::make_pair(false, false);
        }
    }

    if (r.length() == 2 && !is_term(r[0])) {
        return std::make_pair(true, true);
    }

    return std::make_pair(true, false);
}

std::pair<bool, bool> check_right(std::string l, std::string r)
{
    if (l.length() != 1 || is_term(l[0])) {
        return std::make_pair(false, false);
    } else if (l[0] == 'S' && r.length() == 1 && !is_eps(r)) {
        if (r[0] == 'A') {
            return std::make_pair(true, true);
        }

        return std::make_pair(true, false);
    } else if (is_eps(r)) {
        if (l[0] == 'S') {
            return std::make_pair(true, true);
        }

        return std::make_pair(true, false);
    } else if (r.length() == 1) {
        if (is_term(r[0])) {
            return std::make_pair(true, true);
        }

        return std::make_pair(false, false);
    }

    for (int i = 0; i < (int) r.length() - 1; i++) {
        if (!is_term(r[i])) {
            return std::make_pair(false, false);
        }
    }

    if (r.length() == 2 && !is_term(r[1])) {
        return std::make_pair(true, true);
    }

    return std::make_pair(true, false);
}

int main()
{
    std::string l, r;
    bool is_right = true, is_left = true, is_laut = true, is_raut = true;

    while (std::cin >> l >> r) {
        if (l.length() > r.length()) {
            std::cout << 2 << std::endl;
            return 0;
        }

        auto pl = check_left(l, r), pr = check_right(l, r);

        if (!pl.first) {
            is_left = false;
        }

        if (!pl.second) {
            is_laut = false;
        }

        if (!pr.first) {
            is_right = false;
        }

        if (!pr.second) {
            is_raut = false;
        }
    }

    if (is_laut) {
        std::cout << 311 << std::endl;
        return 0;
    } else if (is_left) {
        std::cout << 31 << std::endl;
        return 0;
    }

    if (is_raut) {
        std::cout << 321 << std::endl;
        return 0;
    } else if (is_right) {
        std::cout << 32 << std::endl;
        return 0;
    }

    std::cout << 21 << std::endl;

    return 0;
}
