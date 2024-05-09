#include <stddef.h>

namespace Sample {
    template <typename T, size_t rows, size_t cols>
    class Matrix
    {
        class Row
        {
            T row[cols]{};
        public:
            T& operator[] (size_t j) { return row[j]; }
            const T& operator[] (size_t j) const { return row[j]; }
        };
        Row mtx[rows]{};
        
    public:
        Row& operator[] (size_t i) { return mtx[i]; }
        const Row& operator[] (size_t i) const { return mtx[i]; }
    };
}
