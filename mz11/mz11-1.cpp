#include <stdint.h>
#include <vector>

void process(std::vector<uint64_t> &v, uint32_t s)
{
    auto it = v.begin();
    uint32_t i = 0;
    uint64_t sum = 0;

    while (it != v.end() || i == s) {
        if (i == s) {
            auto dist = std::distance(v.begin(), it);
            v.insert(it, sum);
            it = v.begin() + dist + 1;
            i = 0;
        } else {
            sum += *it;
            ++i;
            ++it;
        }
    }
}
