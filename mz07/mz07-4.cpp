#include <iostream>

// хуйня

namespace Game {
    template <typename T>
    class Coord
    {
    public:
        typedef T value_type;
        value_type row;
        value_type col;
        Coord(value_type r = 0, value_type c = 0) : row(r), col(c) { }
    };

    template <typename value_type>
    value_type diff(value_type a, value_type b)
    {
        return (a > b) ? a - b : b - a;
    }

    template <typename T>
    typename Coord<T>::value_type dist(Coord<T> range, Coord<T> a, Coord<T> b)
    {
        typename Coord<T>::value_type diff_x = diff(a.col, b.col);

        if ((a.col & 1 && a.row < b.row) || (!(a.col & 1) && a.row > b.row)) {
            return diff_x + diff(a.row, b.row) - diff_x / 2;
        } else if ((!(a.col & 1) && a.row < b.row) || (a.col & 1 && a.row > b.row)) {
            return diff_x + diff(a.row, b.row) - (diff_x + 1) / 2;
        }

        return diff_x;
    }
}

int main()
{
    using namespace Game;
    Coord<int> c1(4, 0), c2(5, 4), range(10, 10);
    std::cout << dist(range, c1, c2) << std::endl;
}