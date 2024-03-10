#include <algorithm>
#include <vector>
#include <numeric>
#include <iostream>

class Arena
{
    std::size_t len;
    Item *mem;
    std::vector<bool> free;
    int cnt_free;
public:
    explicit Arena(std::size_t size) :
        len(size / sizeof(Item)), mem(new Item[len]),
        free(std::vector<bool>(len, true)), cnt_free(len) { }
    ~Arena() { delete[] mem; }
    Item * get()
    {
        if (!cnt_free) {
            return nullptr;
        }

        cnt_free--;

        auto block_it = std::find(free.begin(), free.end(), true);
        *block_it = false;
        return &mem[block_it - free.begin()];
    }
    void put(Item *i)
    {
        free[i - mem] = true;
        cnt_free++;
    }
};
