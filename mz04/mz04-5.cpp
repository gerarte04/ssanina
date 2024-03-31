#include <iostream>
#include <list>

int main()
{
    std::list<int> l;
    int x;

    while (std::cin >> x && x != 0) {
        l.push_back(x);
    }

    while (std::cin >> x) {
        if (x < 0) {
            if (-x <= (int) l.size()) {
                auto it = l.begin();
                
                for (x++; x < 0; x++) {
                    it++;
                }

                l.erase(it);
            }
        } else {
            int y;
            std::cin >> y;
            
            if (x > (int) l.size()) {
                l.push_back(y);
            } else {
                auto it = l.begin();
                
                for (x--; x > 0; x--) {
                    it++;
                }
                
                l.insert(it, y);
            }
        }
    }

    for (auto it = l.begin(); it != l.end(); it++) {
        std::cout << *it << std::endl;
    }

    l.clear();

    return 0;
}
