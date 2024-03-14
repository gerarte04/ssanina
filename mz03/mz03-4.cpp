#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"

int main(int argc, char **argv)
{
    using namespace numbers;
    
    complex c(argv[1]);
    double r = std::stod(argv[2]);
    int n = std::stoi(argv[3]);
    std::vector<std::string> func(&argv[4], &argv[argc]);

    double b = 2 * M_PI, step = b / n;
    complex x, next = c + r;
    complex sum;

    for (double t = 0; t < b; t += step) {
        x = next;
        next = c + complex(r * cos(t), r * sin(t));
        sum += eval(func, (x + next) / 2) * (next - x);
    }

    std::cout << sum.to_string() << std::endl;

    return 0;
}
