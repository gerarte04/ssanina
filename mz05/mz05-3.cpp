#include <algorithm>
#include <map>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <time.h>

class Date
{
    std::map<std::string, int> marks;
public:
    static void normalize_date(std::string &s)
    {
        std::tm t;
        std::istringstream iss(s);
        iss >> std::get_time(&t, "%Y/%m/%d");

        std::ostringstream oss;
        oss << std::put_time(&t, "%Y/%m/%d");
        s = oss.str();
    }
    void add_mark(std::string name, int mark)
    {
        marks[name] = mark;
    }
    std::string operator[] (std::string name)
    {
        if (marks.find(name) == marks.end()) {
            return ".";
        }

        return std::to_string(marks[name]);
    }
};

int main()
{
    std::vector<std::string> names;
    std::map<std::string, Date> dates;
    std::string name;

    while (std::cin >> name) {
        names.push_back(name);
        std::string date;
        int mark;
        std::cin >> date >> mark;

        Date::normalize_date(date);
        dates[date].add_mark(name, mark);
    }

    std::cout << ". ";

    for (auto &it : dates) {
        std::cout << it.first << ' ';
    }

    std::cout << std::endl;
    std::sort(names.begin(), names.end());
    auto it_end = std::unique(names.begin(), names.end());
    names.resize(std::distance(names.begin(), it_end));

    for (const std::string &name : names) {
        std::cout << name << ' ';

        for (auto &it : dates) {
            std::cout << it.second[name] << ' ';
        }

        std::cout << std::endl;
    }

    return 0;
}
