#include <iostream>
#include <string>
#include <cmath>
#include <vector>
 
#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"
 
int main (int argc, char **argv) {
    numbers::complex c(argv[1]);
    double r = std::stod(argv[2]);
    int n = std::stoi(argv[3]);
    std::vector<std::string> function(argv + 4, argv + argc);
    double seg = 2 * M_PI / n;
    numbers::complex result;
    numbers::complex vec_prev(1, 0);
    for (int i = 1; i <= n; i++) {
        double phi = seg * i;
        numbers::complex vec(std::cos(phi), std::sin(phi));
        numbers::complex r_c(r, 0);
        result += numbers::eval(function, c + r_c * r_c * vec) * (vec - vec_prev);
        vec_prev = vec;
    }
    std::cout << result.to_string() << std::endl;
}
