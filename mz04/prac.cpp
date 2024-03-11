#include <iostream>
#include <vector>

template <class T>

T abs(const T &a)
{
    return (a >= 0) ? a : -a;
}

template <class T, int SIZE = 10>

class Stack // Stack<char, 20> s;
{
    T st[SIZE];
    int top = 0;
public:
    void push(T a)
    {
        if (top == SIZE) {
            throw 99;
        } else {
            st[top++] = a;
        }
    }
    T pop()
    {
        if (top == 0) {
            throw 99;
        } else {
            return st[--top];
        }
    }
};

void f1()
{
    std::vector<int> v(10, 5);
    auto p = v.end();
    auto rp = v.rbegin();

    while (p != v.begin()) {
        std::cout << *--p << ' ';
    }

    std::cout << std::endl;
    
    while (rp != v.rend()) {
        std::cout << *rp++ << ' ';
    }

    std::cout << std::endl;
}

int main()
{
    int m[] = { 1, 2, 3 };
    std::vector<int> v(m, m + 3);
    std::cout << &m[1] << ' ' << &v[1] << std::endl;
    v.erase(v.begin());
    std::cout << &m[1] << ' ' << &v[0] << std::endl;
}
