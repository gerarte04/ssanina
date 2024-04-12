#include <iostream>
#include <map>

constexpr unsigned int MOD = 4294967161;

int main()
{
    std::map<std::pair<unsigned int, unsigned int>, unsigned long> mtx;
    
    unsigned int r = 0, c = 0;
    unsigned long v = 0;
    std::cin >> r >> c >> v;

    while (!(r == 0 && c == 0 && v == MOD)) {
        mtx[std::make_pair(r, c)] = v % MOD;
        std::cin >> r >> c >> v;
    }

    while (std::cin >> r >> c >> v) {
        mtx[std::make_pair(r, c)] += v % MOD;
        mtx[std::make_pair(r, c)] %= MOD;
    }

    for (const auto &[cell, val]: mtx) {
        if (val != 0) {
            std::cout << cell.first << ' ' << cell.second << ' ' << val << std::endl;
        }
    }

    return 0;
}
