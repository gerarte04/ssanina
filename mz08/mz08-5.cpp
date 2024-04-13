#include <chrono>
#include <iostream>
#include <string>

/*
parse и from_stream не реализованы в gcc 13 libstd++
https://en.cppreference.com/w/cpp/compiler_support#C.2B.2B20_library_features
*/

int get_next(std::string &s, const std::string &delim)
{
    size_t pos = s.find(delim);
    int val = std::stoi(s.substr(0, pos));
    s.erase(0, pos + delim.length());
    return val;
}

std::chrono::year_month_day parse_ymd(const std::string &s)
{
    std::string split(s), dl = "-";
    int y = get_next(split, dl), m = get_next(split, dl), d = get_next(split, dl);

    return std::chrono::year_month_day(
        std::chrono::year(y),
        std::chrono::month(m),
        std::chrono::day(d)
    );
}

int main()
{
    std::string s;
    std::cin >> s;
    std::chrono::sys_days prev = parse_ymd(s);
    int total_diff = 0;

    while (std::cin >> s) {
        std::chrono::sys_days cur = parse_ymd(s);
        std::chrono::days diff = cur - prev;
        total_diff += abs(diff.count());
        prev = cur;
    }

    std::cout << total_diff << std::endl;

    return 0;
}
