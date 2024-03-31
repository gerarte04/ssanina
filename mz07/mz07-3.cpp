#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

class Factory
{
private:
    Factory() { }
    Factory(const Factory& f) = delete;
    Factory& operator= (const Factory&) = delete;
public:
    static Factory& factory_instance()
    {
        static Factory single;
        return single;
    }
    Figure* make_figure(const std::string &data) const
    {
        std::istringstream iss(data);
        std::string type, params;
        iss >> type;
        getline(iss, params);

        static std::map<std::string, std::function<Figure*(std::string)>> makers = {
            { "R", Rectangle::make },
            { "S", Square::make },
            { "C", Circle::make }
        };

        return makers[type](params);
    }
};

int main()
{
    std::vector<std::unique_ptr<Figure>> figs;
    Factory &factory = Factory::factory_instance();
    std::string data;

    while (std::getline(std::cin, data)) {
        figs.push_back(std::unique_ptr<Figure>(factory.make_figure(data)));
    }

    std::stable_sort(figs.begin(), figs.end(),
        [](const auto &a, const auto &b) { return a->get_square() < b->get_square(); });

    for (auto it = figs.begin(); it != figs.end(); ++it) {
        std::cout << (*it)->to_string() << std::endl;
    }

    return 0;
}
