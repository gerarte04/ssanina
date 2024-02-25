#include <iostream>

int main()
{
    char c = getc(stdin);
    char prev = c;
    bool is_num = false;

    while ((c = getc(stdin)) != EOF) {
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
    }

    if (prev != EOF) {
        std::cout << prev;
    }

    return 0;
}
