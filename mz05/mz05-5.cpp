#include <iostream>
#include <map>

constexpr unsigned int MOD = 4294967161;

int main()
{
    std::map<unsigned int, std::map<unsigned int, unsigned long>> mtx1, mtx2, res;

    unsigned int r = 0, c = 0, v = 0;
    std::cin >> r >> c >> v;

    while (!(r == 0 && c == 0 && v == MOD)) {
        mtx1[r][c] = v % MOD;
        std::cin >> r >> c >> v;
    }

    while (std::cin >> r >> c >> v) {
        mtx2[r][c] = v % MOD;
    }

    for (const auto &[i1, row] : mtx1) {
        for (const auto &[j1, v1] : row) {
            for (const auto &[j2, v2] : mtx2[j1]) {
                res[i1][j2] += v1 * v2 % MOD;
                res[i1][j2] %= MOD;
            }
        }
    }

    for (const auto &[i, row] : res) {
        for (const auto &[j, val] : row) {
            if (val != 0) {
                std::cout << i << ' ' << j << ' ' << val << std::endl;
            }
        }
    }

    return 0;
}
