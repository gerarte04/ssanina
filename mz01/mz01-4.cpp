#include <iomanip>
#include <iostream>
#include <math.h>

int main()
{
    double av = 0, sq_av = 0;
    int n = 0;

    double x;

    while (std::cin >> x) {
        n++;
        av += (x - av) / n;
        sq_av += (x * x - sq_av) / n;
    }

    std::cout << std::fixed << std::showpoint << std::setprecision(10)
        << av << std::endl << sqrt(sq_av - av * av) << std::endl;

    return 0;
}
