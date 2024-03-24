#include <functional>

template <class T>
T myfilter(const T &v, std::function<bool(typename T::value_type)> func)
{
    typename T::const_iterator it;
    T v2;

    for (it = v.begin(); it != v.end(); ++it) {
        if (func(*it)) {
            v2.push_back(*it);
        }
    }

    return v2;
}
