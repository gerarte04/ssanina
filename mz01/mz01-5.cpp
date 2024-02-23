#include <iomanip>
#include <iostream>

constexpr int CNT_OCTS = 16;

int main()
{
    unsigned int n_oct;
    std::cin >> std::hex;

    while (std::cin >> n_oct) {
        unsigned int x = 0;
        unsigned int oct;

        for (int i = 1; i <= CNT_OCTS && std::cin >> oct; i++) {
            x = (x << __CHAR_BIT__) | oct;

            if (!(i % sizeof(x))) {
                std::cout << x << std::endl;
                x = 0;
            }
        }
    }

    return 0;
}
