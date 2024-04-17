#include <iostream>

/*
S -> A
A -> aAd | aBd
B -> bBc | eps
*/

void pc(char a)
{
    if (a) {
        std::cout << a;
    }
}

void B(int k)
{
    if (k >= 2) {
        pc('b');
        B(k - 2);
        pc('c');
    }
}

void S(int k, int ka)
{
    if (ka == 2) {
        pc('a');
        B(2);
        pc('d');
    }
    else if (ka > 2) {
        pc('a');
        S(k, ka - 2);
        pc('d');
        if (k - ka == 2) {
            pc('\n');
        }
        pc('a');
        B(ka);
        pc('d');
        if (k - ka == 2) {
            pc('\n');
        }
    }
}

int main()
{
    int k;
    std::cin >> k;

    S(k, k - 2);

    return 0;
}
