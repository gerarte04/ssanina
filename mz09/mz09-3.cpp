#include <iostream>

// S = aSb | a0A1b | a0Ab1
// A = 0A1 | 01

// хуета помойная

char c;
void gc()
{
    if (!(std::cin >> c)) {
        c = '\0';
    }
}

void A()
{
    if (c == '0') {
        gc();
        if (c == '1') { gc(); }
        else {
            A();
            if (c == '1') { gc(); }
            else { throw c; }
        }
    } else { throw c; }
}

void S()
{
    if (c != 'a') { throw c; }
    gc();
    if (c == 'a') {
        S();
        if (c == 'b') { gc(); }
        else { throw c; }
    } else if (c == '0') {
        gc(); A();
        if (c == '1') {
            gc();
            if (c == 'b') { gc(); }
            else { throw c; }
        } else if (c == 'b') {
            gc();
            if (c == '1') { gc(); }
            else { throw c; }
        } else { throw c; }
    } else { throw c; }
}

int main()
{
    try {
        gc(); S();
        if (c) { throw c; }
        std::cout << 1 << std::endl;
    } catch (char) { std::cout << 0 << std::endl; }

    return 0;
}
