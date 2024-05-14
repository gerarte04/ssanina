#include <future>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>

std::pair<unsigned long, unsigned long> calculate(unsigned long iter_cnt, unsigned int seed)
{
    static constexpr double x_cntr = 0.5, y_cntr = 0.5, sq_rad = 0.25;

    unsigned long inside = 0;

    for (unsigned long i = 0; i < iter_cnt; ++i) {
        double x = (double) rand_r(&seed) / RAND_MAX;
        double y = (double) rand_r(&seed) / RAND_MAX;

        if (pow(x_cntr - x, 2) + pow(y_cntr - y, 2) <= sq_rad) {
            ++inside;
        }
    }

    return std::make_pair(inside, iter_cnt);
}

int main(int argc, char **argv)
{
    static constexpr int BASE = 10;

    unsigned long async_cnt = strtoul(argv[1], NULL, BASE);
    unsigned long iter_cnt = strtoul(argv[2], NULL, BASE);

    std::vector<std::future<std::pair<unsigned long, unsigned long>>> ftrs;

    for (unsigned long i = 0; i < async_cnt; ++i) {
        ftrs.push_back(std::async(calculate, iter_cnt, i));
    }

    unsigned long inside = 0, total = 0;
    
    for (auto &f : ftrs) {
        auto res = f.get();
        inside += res.first;
        total += res.second;
    }

    std::cout << std::setprecision(20) << (double) inside / total * 4 << std::endl;

    return 0;
}
