#include <complex>
#include <array>
#include <limits>
#include <utility>
#include <vector>
#include <iostream>

namespace Equations {
    template <class T>
    bool is_zero(T a)
    {
        T zero = T(32.0) * std::numeric_limits<T>::epsilon();
        double eps = 1e-6;
        double diff = std::norm(a - zero);
        return diff < eps && diff > -eps;
    }

    template <class T>
    std::pair<bool, std::vector<T>> quadratic(std::array<T, 3> v)
    {
        if(is_zero(v[2])){
            if (is_zero(v[1])) {
                if (is_zero(v[0])) {
                    return std::make_pair(false, std::vector<T>(0));
                } else {
                    return std::make_pair(true, std::vector<T>(0));
                }
            } else {
                return std::make_pair(true, std::vector<T> { -v[0] / v[1] });
            }
        }

        T discr = v[1] * v[1] - T(4.0) * v[0] * v[2];
        return std::make_pair(true, std::vector<T>
        {
            (-v[1] - std::sqrt(discr)) / (T(2.0) * v[2]),
            (-v[1] + std::sqrt(discr)) / (T(2.0) * v[2])
        });
    }
}
