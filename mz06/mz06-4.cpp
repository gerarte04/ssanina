#include <algorithm>
#include <vector>

template <class T, class K>
K myremove(T abegin, T aend, K vbegin, K vend)
{
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
            std::remove_if(vbegin, vend, [el_it](const typename K::value_type &a) { return &a == &(*el_it); });
            ++off;
            --vend;
        }
    }

    return vend;
}
