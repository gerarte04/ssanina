#include <iostream>

class S
{
    int n{};
    int cnt{};
    bool write = true;
public:
    S()
    {
        if (!(std::cin >> n)) {
            write = false;
        } else {
            ++cnt;
        }
    }
    S(S &&v)
    {
        n = v.n;
        cnt = v.cnt;
        int a;
        
        if (!(std::cin >> a)) {
            write = false;
        } else {
            n += a;
            ++cnt;
        }
    }
    ~S()
    {
        if (!write && cnt) {
            std::cout << n << std::endl;
        }
    }
    operator bool() const { return write; }
};
