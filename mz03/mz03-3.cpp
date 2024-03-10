#include <functional>
#include <map>
#include <string>
#include <vector>

namespace numbers {
    complex eval(const std::vector<std::string> &args, const complex &z)
    {
        complex_stack st;

        static std::map<char, std::function<void(const std::string &)>> opers = {
            { '(', [&st](const std::string &arg) { st = st << complex(arg); } },
            { 'z', [&st, &z](const std::string &arg) { st = st << z; } },
            { '!', [&st](const std::string &arg) { st = st << +st; } },
            { ';', [&st](const std::string &arg) { st = ~st; } },
            { '~', [&st](const std::string &arg) { st = ~st << ~+st; } },
            { '#', [&st](const std::string &arg) { st = ~st << -+st; } },
            { '+', [&st](const std::string &arg) { st = ~~st << st[st.size() - 2] + +st; } },
            { '-', [&st](const std::string &arg) { st = ~~st << st[st.size() - 2] - +st; } },
            { '*', [&st](const std::string &arg) { st = ~~st << st[st.size() - 2] * +st; } },
            { '/', [&st](const std::string &arg) { st = ~~st << st[st.size() - 2] / +st; } }
        };

        for (const std::string &s : args) {
            opers[s[0]](s);
        }

        return +st;
    }
}
