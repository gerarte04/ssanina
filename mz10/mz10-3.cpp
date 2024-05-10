#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

int main()
{   
    std::map<std::string, std::vector<std::pair<char, std::string>>> moves;
    std::set<std::string> ends;
    std::string cur;

    std::string first, last;
    char c;
    std::cin >> first;

    while (first != "END") {
        std::cin >> c >> last;
        moves[first].push_back(std::make_pair(c, last));
        std::cin >> first;
    }

    std::cin >> last;

    while (last != "END") {
        ends.insert(last);
        std::cin >> last;
    }

    std::cin >> cur;
    int cnt_read = 0;
    bool success = false;
    auto print = [&success, &cnt_read, &cur]() {
        std::cout << success << '\n' << cnt_read << '\n' << cur << std::endl;
    };

    while (std::cin >> c) {
        success = false;
        
        for (auto &[cm, tgt] : moves[cur]) {
            if (c == cm) {
                success = true;
                cur = tgt;
                ++cnt_read;
            }
        }

        if (!success) {
            print();
            return 0;
        }
    }

    if (ends.find(cur) == ends.end()) {
        success = false;
    }

    print();

    return 0;
}
