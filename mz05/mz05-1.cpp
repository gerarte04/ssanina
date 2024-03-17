#include <algorithm>
#include <iostream>
#include <vector>

int cnt_ones(unsigned int x)
{
    int cnt = 0;
    
    while (x) {
        cnt += x & 1;
        x >>= 1;
    }

    return cnt;
}

int main()
{
    std::vector<unsigned int> v;
    unsigned int n;

    while (std::cin >> n) {
        v.push_back(n);
    }

    auto comp = [](unsigned int x, unsigned int y) {
        return cnt_ones(x) < cnt_ones(y);
    };
    
    std::stable_sort(v.begin(), v.end(), comp);

    for (auto it = v.begin(); it != v.end(); it++) {
        std::cout << *it << std::endl;
    }

    return 0;
}
