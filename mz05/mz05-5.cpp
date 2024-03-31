#include <iostream>
#include <map>
#include <set>

// хуйня

constexpr unsigned int MOD = 4294967161;

int main()
{
    std::map<std::pair<unsigned int, unsigned int>, unsigned long> mtx1, mtx2;
    std::set<unsigned int> used_rows, used_cols, used_both;

    unsigned int r = 0, c = 0;
    unsigned int max_rc = 0;
    unsigned long v = 0;
    std::cin >> r >> c >> v;

    while (!(r == 0 && c == 0 && v == MOD)) {
        mtx1[std::make_pair(r, c)] = v % MOD;
        max_rc = (r > max_rc) ? r : max_rc;
        max_rc = (c > max_rc) ? c : max_rc;
        used_rows.insert(r);
        used_both.insert(r);
        used_both.insert(c);

        std::cin >> r >> c >> v;
    }

    while (std::cin >> r) {
        std::cin >> c >> v;
        
        mtx2[std::make_pair(r, c)] = v % MOD;
        max_rc = (r > max_rc) ? r : max_rc;
        max_rc = (c > max_rc) ? c : max_rc;
        used_cols.insert(c);
        used_both.insert(r);
        used_both.insert(c);
    }

    for (auto i = used_rows.begin(); i != used_rows.end(); ++i) {
        for (auto j = used_cols.begin(); j != used_cols.end(); ++j) {
            unsigned long res = 0;

            for (auto k = used_both.begin(); k != used_both.end(); ++k) {
                res += mtx1[std::make_pair(*i, *k)] * mtx2[std::make_pair(*k, *j)] % MOD;
                res %= MOD;
            }

            if (res != 0) {
                std::cout << *i << ' ' << *j << ' ' << res << std::endl;
            }
        }
    }

    return 0;
}
