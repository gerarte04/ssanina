#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

int main()
{
    std::vector<std::pair<char, std::string>> rules;
    std::map<char, std::set<char>> exps;
    std::set<char> rcb = { 'S' };
    char l;
    std::string r;

    while (std::cin >> l >> r) {
        rules.push_back(std::make_pair(l, r));
        
        for (char &c : r) {
            if (c >= 'A' && c <= 'Z') {
                exps[l].insert(c);
            }
        }
    }

    int cnt_moved;

    do {
        cnt_moved = 0;
        std::set<char> new_rcb;

        for (auto &lc : rcb) {
            for (auto &rc : exps[lc]) {
                new_rcb.insert(rc);
                ++cnt_moved;
            }

            exps.erase(lc);
        }

        for (auto &nlc : new_rcb) {
            rcb.insert(nlc);
        }
    } while (cnt_moved);

    for (const auto &[lr, rr] : rules) {
        if (rcb.find(lr) != rcb.end()) {
            std::cout << lr << ' ' << rr << std::endl;
        }
    }

    return 0;
}
