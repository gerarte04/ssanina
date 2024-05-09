#include <stdint.h>
#include <string>

std::string gen_power(uint32_t power)
{
    if (!power) {
        return "1";
    } else if (power == 1) {
        return "x";
    }

    std::string res = gen_power(power / 2) + "!*";

    if (power & 1) {
        res += "x*";
    }

    return res;
}
