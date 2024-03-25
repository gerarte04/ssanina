#include <vector>
#include <algorithm>
#include <iostream>

template <class T, class K>
K myremove(T abegin, T aend, K vbegin, K vend)
{
    typename T::difference_type dist = std::distance(vbegin, vend);
    std::vector<typename T::value_type> copy(abegin, aend);
    std::sort(copy.begin(), copy.end());
    auto it_end = std::unique(copy.begin(), copy.end());
    copy.resize(std::distance(copy.begin(), it_end));

    int off = 0;

    for (auto it = copy.begin(); it != copy.end(); ++it) {
        auto el_it = vbegin;
        int i;

        for (i = 0; i < *it - off && el_it != vend; ++i) {
            ++el_it;
        }

        if (i == *it - off) {
            std::remove(vbegin, vend, *el_it);
            ++off;
            --dist;
        }
    }

    vend = vbegin;
    for (int i = 0; i < dist; i++) {
        vend++;
    }

    for (auto it = vbegin; it != vend; it++) {
        std::cout << *it << std::endl;
    }

    return vend;
}

int main() {
    std::vector<int> nums = { 0, 1, 2, 3, 4, 5 };
    std::vector<int> del = { 0, 5, 5, 4 };

    auto it = myremove(del.begin(), del.end(), nums.begin(), nums.end());
    std::cout << *(--it) << std::endl;
}