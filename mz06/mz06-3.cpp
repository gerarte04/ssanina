#include <functional>
#include <vector>

template <class T>
void myapply(T begin, T end, std::function<void(typename T::value_type)> f)
{
    for (auto it = begin; it != end; ++it) {
        f(*it);
    }
}

template <class T>
std::vector<std::reference_wrapper<typename std::iterator_traits<T>::value_type>>
myfilter2(T begin, T end, std::function<bool(typename std::iterator_traits<T>::value_type)> f)
{
    std::vector<std::reference_wrapper<typename std::iterator_traits<T>::value_type>> v;

    for (auto it = begin; it != end; ++it) {
        if (f(*it)) {
            v.push_back(*it);
        }
    }

    return v;
}
