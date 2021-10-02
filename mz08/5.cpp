#include <complex>
#include <utility>
#include <vector>
#include <limits>
#include <array>

namespace Equations {
    template<typename Type>
    auto quadratic(std::array<Type, 3> v) {
        std::vector<Type> solutions;
        bool is_identity = false;
        auto eps = decltype(v[0].real())(32) *
            std::numeric_limits<decltype(v[0].real())>::epsilon();
        if(std::norm(v[2]) < eps) {
            if(std::norm(v[1]) < eps) {
                if(std::norm(v[0]) < eps) {
                    is_identity = true;
                } else {
                }
            } else {
                solutions.push_back(-v[0] / v[1]);
            }
        } else {
            auto sqrt_disc = std::sqrt(v[1] * v[1] - Type(4.0) * v[0] * v[2]);
            solutions.push_back((-v[1] + sqrt_disc)/(Type(2.0) * v[2]));
            solutions.push_back((-v[1] - sqrt_disc)/(Type(2.0) * v[2]));
        }
        return std::make_pair(!is_identity, solutions);
    }
}

//#define _TEST_NEW_
#ifdef _TEST_NEW_
#include <iostream>
int main() {
    using namespace std::complex_literals;

    std::array v1{ 1.0 + 2.0i, 2.0 + 0i, 3.0 + 1.3i };

    auto [res, v2] = Equations::quadratic(v1);
    std::cout << res << std::endl;
    for(auto item : v2) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}
#endif
#ifdef _TEST_OLD_
#include <iostream>
int main() {
    std::array<std::complex<double>, 3> v1{
        std::complex<double>(0),
        std::complex<double>(0),
        std::complex<double>(0)
    };
    auto res = Equations::quadratic(v1);
    std::cout << res.first << std::endl;
    for(auto item : res.second) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}
#endif
