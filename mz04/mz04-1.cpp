#include <vector>

void process(
    const std::vector<unsigned long> &v1,
    std::vector<unsigned long> &v2,
    int step
)
{
    auto it1 = v1.begin();

    if (it1 == v1.end()) {
        return;
    }

    for (auto it2 = v2.rbegin(); it2 != v2.rend(); it2++) {
        *it2 += *it1;

        if (it1 >= v1.end() - step) {
            break;
        }

        it1 += step;
    }
}
