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
        auto diff_x = diff(a.col, b.col), diff_y = diff(a.row, b.row), sub_y = 0;

        if (a.row == b.row) {
            return diff_x;
        }

        if ((a.col & 1) ^ (a.row > b.row)) {
            sub_y = diff_x / 2;
        } else {
            sub_y = (diff_x + 1) / 2;
        }

        if (diff_y > sub_y) {
            return diff_x + diff_y - sub_y;
        }

        return diff_x;
    }
}
