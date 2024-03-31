#include <functional>

template <class T>
void selection_sort(
    T begin, T end,
    std::function<bool(typename T::value_type, typename T::value_type)> comp =
    [](const typename T::value_type &a, const typename T::value_type &b) { return a < b; }
)
{
    for (T it = begin; it != end; ++it) {
        T min = it;

        for (T jt = it; jt != end; ++jt) {
            if (comp(*jt, *min)) {
                min = jt;
            }
        }

        std::swap(*min, *it);
    }
}
