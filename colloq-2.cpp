#include <iostream>
#include <string>
using namespace std;

/*
программа из колка пропускает строки вида a?b, где ? - любой символ; хотя не должна
классно составили задание
*/

void S();

char c;
void gc() { std::cin >> c; }
struct alt1 { string s = "aSb"; };
struct alt2 { string s = "cc"; };
alt1 a1;
alt2 a2;

template <class T>
void analyze(T alt)
{
    for (int i = 1; i < alt.s.length(); ++i) {
        gc();
        if (alt.s[i] == 'S') { S(); }
        else if (alt.s[i] != c) { throw c; }
    }
    gc();
}

void S()
{
    if (c == 'a') {
        analyze(a1);
    } else if (c == 'c') {
        analyze(a2);
    }
}

int main()
{
    try {
        gc();
        S();
        if (std::cin.eof()) { cout << "OK\n"; }
        else { throw c; }
    } catch (char c) { cout << c << " NO\n"; }
}
