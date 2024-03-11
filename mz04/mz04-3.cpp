#include <vector>
#include <iostream>
#include <algorithm>

void process(const std::vector<int> &v1, std::vector<int> &v2)
{
    std::vector<long> copy = std::vector<long>(v1.begin(), v1.end());
    std::sort(copy.begin(), copy.end());
    auto it_end = std::unique(copy.begin(), copy.end());
    copy.resize(std::distance(copy.begin(), it_end));
    int cnt_failed = 0;

    for (auto it = copy.begin(); it != copy.end(); it++) {
        if (*it >= 0) {
            *it -= std::distance(copy.begin(), it) - cnt_failed;

            if (*it >= 0 && *it < long(v2.size())) {
                v2.erase(v2.begin() + *it);
            }
        } else {
            cnt_failed++;
        }
    }
}
