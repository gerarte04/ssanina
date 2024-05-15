#include <iostream>
#include <list>
#include <map>
#include <string>

int main()
{
    std::map<std::string, int> labels;
    std::list<std::string> elems;
    
    std::string s;
    int cur = 1;

    while (std::cin >> s) {
        auto last = s.end() - 1;
        
        if (*last == ':') {
            s.erase(last);
            labels[s] = cur;
        } else {
            elems.push_back(s);
            ++cur;
        }
    }

    for (const auto &el : elems) {
        if (labels.find(el) != labels.end()) {
            std::cout << labels[el] << std::endl;
        } else {
            std::cout << el << std::endl;
        }
    }

    return 0;
}
