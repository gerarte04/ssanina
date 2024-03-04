#include <map>
#include <string>
#include <vector>
#include <functional>

namespace numbers {
    std::map<char, std::function<void()>> opers = {
        '+': [complex_stack & st](std::string s) {st << complex(s);}
    }
    complex eval(const std::Vector<std::string> &args, const complex &z)
    {
        complex_stack st;
        for (std::string s : args) {
            complex c, d;
            switch (s[0]) {
            case '(':
                st << complex(s);
                break;
            case 'z':
                st << complex(z.re(), z.im());
                break;
            case '!':
                st << +st;
                break;
            case ';':
                ~st;
                break;
            case '~':
                c = +st;
                ~st;
                st << ~c;
                break;
            case '#':
                c = +st;
                ~st;
                st << -c;
                break;
            case '+':
                d = +st;
                c = +st;
                st << c + d;
                break;
            case '-':
                d = +st;
                c = +st;
                st << c - d;
                break;
            case '*':
                d = +st;
                c = +st;
                st << c * d;
                break;
            case '/':
                d = +st;
                c = +st;
                st << c / d;
                break;
            }
        }
    }
}