#include <iostream>

/*
S -> aAd
A -> aAd | bBc
B -> bBc | eps
*/

void pc(char c)
{
    std::cout << c;
}

void B(int i)
{
    if (i > 0) {
        pc('b');
        B(i - 2);
        pc('c');
    }
}

void A(int k, int i)
{
    if (k == i) {
        pc('b');
        B(i - 2);
        pc('c');
    } else {
        pc('a');
        A(k - 2, i);
        pc('d');
    }
}

void S(int k, int i)
{
    pc('a');
    A(k - 2, i);
    pc('d');
}

int main()
{
    int k;
    std::cin >> k;

    if (k >= 4 && !(k & 1)) {
        for (int i = 2; i < k; i += 2) {
            S(k, i);
            std::cout << std::endl;
        }
    }

    return 0;
}
