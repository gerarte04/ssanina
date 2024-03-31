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

    while (std::cin >> r) {
        std::cin >> c >> v;
        mtx[std::make_pair(r, c)] += v % MOD;
        mtx[std::make_pair(r, c)] %= MOD;
    }

    for (auto it = mtx.begin(); it != mtx.end(); it++) {
        if (it->second != 0) {
            std::cout << it->first.first << ' ' << it->first.second << ' ' << it->second << std::endl;
        }
    }

    return 0;
}
