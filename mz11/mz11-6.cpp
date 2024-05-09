#include <iostream>

char c;
void gc()
{
    if (!(std::cin >> c)) {
        c = '\0';
    }
}

void A()
{
    if (c == 'c') {
        gc(); A();
        if (c == 'd') { gc(); }
        else { throw c; }
    } else if (c == 'e') { gc(); }
    else { throw c; }
}

void B()
{
    if (c == 'b') { gc(); B(); }
    else if (c == 'd' || c == '\0') { gc(); }
    else { throw c; }
}

void S()
{
    if (c == 'a') {
        gc(); A();
        if (c == 'b') { gc(); }
        else { throw c; }
    }
    else if (c == 'c') { gc(); B(); }
    else { throw c; }
}

int main()
{
    try {
        gc();
        S();
        if (c) { throw c; }
        std::cout << 1 << std::endl;
    } catch (char) { std::cout << 0 << std::endl; }

    return 0;
}
