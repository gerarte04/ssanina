#include <iostream>
#include <set>
#include <vector>
#include <string>

int main()
{
    std::vector<std::set<char>> alphabets{ {'3', '4'}, {'1', '2'} };
    std::string s;

    while (std::cin >> s) {
        auto cur = alphabets.begin();
        bool belongs = true;

        for (char &c : s) {
            while (cur != alphabets.end() && cur->find(c) == cur->end()) {
                ++cur;
            }
            
            if (cur == alphabets.end()) {
                belongs = false;
                break;
            }
        }

        std::cout << belongs << std::endl;
    }

    return 0;
}
