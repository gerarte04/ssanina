#include <iomanip>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

constexpr int THREAD_CNT = 3;
constexpr int ITER_CNT = 1000000;
constexpr int FRAC_LEN = 10;

double arr[THREAD_CNT]{};

void f(std::mutex &mtx, int k)
{
    int n = (k + 1) * 100;
    int l = (k + 1) % THREAD_CNT;

    for (int i = 0; i < ITER_CNT; ++i) {
        mtx.lock();
        arr[k] += n;
        arr[l] -= n + 1;
        mtx.unlock();
    }
}

int main()
{
    std::vector<std::thread> thrs;
    std::mutex mtx;

    for (int i = 0; i < THREAD_CNT; ++i) {
        thrs.push_back(std::thread(f, std::ref(mtx), i));
    }

    for (std::thread &t : thrs) {
        t.join();
    }

    for (int i = 0; i < THREAD_CNT; ++i) {
        std::cout << std::setprecision(FRAC_LEN) << arr[i] << std::endl;
    }

    return 0;
}
