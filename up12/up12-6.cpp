#include <iomanip>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

void update_accs(
    double &acc1, double &acc2,
    double sum1, double sum2,
    std::mutex &mtx1, std::mutex &mtx2,
    int iter_cnt)
{
    for (int i = 0; i < iter_cnt; ++i) {
        std::scoped_lock lock(mtx1, mtx2);
        acc1 += sum1;
        acc2 += sum2;
    }
}

int main()
{
    static constexpr int FRAC_LEN = 10;
    
    int acc_count, thr_count;
    std::cin >> acc_count >> thr_count;

    std::vector<double> accs(acc_count);
    std::vector<std::mutex> mtxs(acc_count);
    std::vector<std::thread> thrs;

    for (int i = 0; i < thr_count; ++i) {
        int iter_cnt, k1, k2;
        double sum1, sum2;
        std::cin >> iter_cnt >> k1 >> sum1 >> k2 >> sum2;

        thrs.push_back(std::thread(
            update_accs,
            std::ref(accs[k1]), std::ref(accs[k2]),
            sum1, sum2,
            std::ref(mtxs[k1]), std::ref(mtxs[k2]),
            iter_cnt));
    }

    for (std::thread &t : thrs) {
        t.join();
    }

    for (const double &a : accs) {
        std::cout << std::setprecision(FRAC_LEN) << a << std::endl;
    }

    return 0;
}
