#include <iostream>

constexpr int MAX_NOCODE = 4;

int main()
{
    char c, seq;
    int len = 1;

    if (!std::cin.get(c)) {
        return 0;
    }

    seq = c;

    auto print_seq = [&seq, &len]() {
        if (len <= MAX_NOCODE && seq != '#') {
            for (int i = 0; i < len; i++) {
                std::cout << seq;
            }
        } else {
            std::cout << std::hex << '#' << seq << len << '#';
        }
    };

    while (std::cin.get(c)) {
        if (c != seq) {
            print_seq();
            len = 0;
        }

        seq = c;
        len++;
    }

    print_seq();

    return 0;
}
