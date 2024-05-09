#include <functional>
#include <stdint.h>

void calc_binom(int m, int k, std::function<void(uint64_t)> cb)
{
    static bool is_recur = false;
    bool is_first = !is_recur;
    
    try {
        if (is_first) {
            if (k == 0) {
                throw 1.0;
            }
            
            is_recur = true;
            calc_binom(m - k, k, cb);
        } else {
            if (k == 1) {
                throw 1.0;
            }
            calc_binom(m, k - 1, cb);
        }
    } catch (double res) {
        if (is_first) {
            is_recur = false;
            cb((int)(res + 0.01));
        } else {
            throw res * (m + k) / k;
        }
    }
}
