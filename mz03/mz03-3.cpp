#include <map>
#include <string>
#include <vector>
#include <functional>

namespace numbers {
    std::map<char, std::function<void(complex_stack &, const std::string &, const complex &)>> opers = {
        { '(', [](complex_stack &st, const std::string &arg, const complex &z) { st << complex(arg); } },
        { 'z', [](complex_stack &st, const std::string &arg, const complex &z) { st << complex(z.re(), z.im()); } },
        { '!', [](complex_stack &st, const std::string &arg, const complex &z) { st << +st; } },
        { ';', [](complex_stack &st, const std::string &arg, const complex &z) { ~st; } },
        { '~', [](complex_stack &st, const std::string &arg, const complex &z) {
            complex c = +st;
            ~st;
            st << ~c;
        } },
        { '#', [](complex_stack &st, const std::string &arg, const complex &z) {
            complex c = +st;
            ~st;
            st << -c;
        } },
        { '+', [](complex_stack &st, const std::string &arg, const complex &z) {
            complex d = +st, c = +st;
            st << c + d;
        } },
        { '-', [](complex_stack &st, const std::string &arg, const complex &z) {
            complex d = +st, c = +st;
            st << c - d;
        } },
        { '*', [](complex_stack &st, const std::string &arg, const complex &z) {
            complex d = +st, c = +st;
            st << c * d;
        } },
        { '/', [](complex_stack &st, const std::string &arg, const complex &z) {
            complex d = +st, c = +st;
            st << c / d;
        } }
    };

    complex eval(const std::vector<std::string> &args, const complex &z)
    {
        complex_stack st;

        for (const std::string &s : args) {
            opers[s[0]](st, s, z);
        }

        return +st;
    }
}