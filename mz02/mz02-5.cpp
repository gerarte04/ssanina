#include <string>

class BinaryNumber
{
    std::string n;
public:
    BinaryNumber(const std::string &s = "0") { n = s; }
    operator std::string() const { return n; }
    const BinaryNumber & operator++ ()
    {
        for (int i = n.size() - 1; i >= 0; i--) {
            if (n[i] == '0') {
                n[i] = '1';
                return *this;
            } else {
                n[i] = '0';
            }
        }

        n.insert(n.begin(), '1');
        return *this;
    }
};
