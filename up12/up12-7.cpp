#include <future>
#include <iostream>
#include <stdint.h>
#include <thread>
#include <vector>

template <typename T>
bool is_prime(T n)
{
    if (n <= 1) {
        return false;
    }

    for (T i = 2; i * i <= n; ++i) {
        if (!(n % i)) {
            return false;
        }
    }

    return true;
}

void find_primes(uint64_t low, uint64_t high, int count, std::vector<std::promise<uint64_t>> pms)
{
    int fnd_cnt = 0;
    
    for (uint64_t n = low; n <= high; ++n) {
        if (is_prime(n)) {
            pms[fnd_cnt].set_value(n);
            ++fnd_cnt;

            if (fnd_cnt == count) {
                return;
            }
        }
    }

    try {
        throw high;
    } catch (...) {
        pms[fnd_cnt].set_exception(std::current_exception());
    }
}

int main()
{
    uint64_t low, high;
    int count;
    std::cin >> low >> high >> count;

    std::vector<std::promise<uint64_t>> pms(count);
    std::vector<std::future<uint64_t>> fts;

    for (auto &p : pms) {
        fts.push_back(p.get_future());
    }
    
    std::thread find_thr(find_primes, low, high, count, std::move(pms));

    try {
        for (auto &f : fts) {
            std::cout << f.get() << std::endl;
        }
    } catch (uint64_t ex) {
        std::cout << ex << std::endl;
    }

    find_thr.join();

    return 0;
}
