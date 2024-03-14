#include <vector>

void process(std::vector<long> &v, long threshold)
{
    int len = v.size();
    auto it = v.begin();

    while (it != v.begin() + len) {
        int dist = std::distance(v.begin(), it);

        if (*it >= threshold) {
            v.insert(v.begin() + len, *it);
        }

        it = v.begin() + dist + 1;
    }
}
