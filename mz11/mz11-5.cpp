#include <iostream>

bool scan()
{
    char st = 'S';
    char c;
    
    while (std::cin >> c) {
        switch (st) {
        case 'S':
            if (c == 'a') { st = 'A'; }
            else if (c == 'b') { st = 'B'; }
            else { return 0; }
            break;
        case 'A':
            if (c == 'a') { st = 'S'; }
            else if (c == 'b') { return !(std::cin >> c); }
            else if (c == 'c') { st = 'D'; }
            else { return 0; }
            break;
        case 'B':
            if (c == 'a') { st = 'S'; }
            else { return 0; }
            break;
        case 'D':
            if (c == 'a') { st = 'E'; }
            else if (c == 'b') { st = 'B'; }
            else { return 0; }
            break;
        case 'E':
            if (c == 'a') { st = 'A'; }
            else if (c == 'b') { st = 'B'; }
            else { return 0; }
            break;
        default:
            return 0;
        }
    }

    return st == 'E';
}

int main()
{
    std::cout << scan() << std::endl;

    return 0;
}
