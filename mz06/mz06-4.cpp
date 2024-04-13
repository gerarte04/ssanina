#include <algorithm>
#include <vector>
#include <iostream>

// не робит с листом и read-only T (параша ебаная)

template <class T, class K>
K myremove(T abegin, T aend, K vbegin, K vend)
{
    std::sort(abegin, aend);
    aend = std::unique(abegin, aend);

    int off = 0;

    for (auto it = abegin; it != aend; ++it) {
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
