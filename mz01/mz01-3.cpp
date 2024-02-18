#include <iostream>

int main()
{
    char c = std::cin.get();
    char prev = c;
    bool is_num = false;

    do {
        c = std::cin.get();

        if (isdigit(prev)) {
            if (prev != '0') {
                is_num = true;
                std::cout << prev;
            } else if (is_num || !isdigit(c)) {
                std::cout << prev;
            }
        } else {
            is_num = false;
            std::cout << prev;
        }

        prev = c;
    } while (c != EOF);

    return 0;
}
