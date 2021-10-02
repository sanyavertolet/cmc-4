#include <type_traits>

template<typename T1, typename T2>
using Best_t = decltype(T1()+T2());

#define It_t(It_) typename std::remove_pointer<typename std::iterator_traits<It_>::value_type>::type

#define Best_It_t(It1_, It2_) Best_t<It_t(It1), It_t(It2)>

template<typename Ta, typename Tb>
Best_t<Ta,Tb> scalar_mul_def_mul(const Ta a, const Tb b) {
    return a * b;
}

template<typename Ta, typename Tb>
Best_t<Ta,Tb> scalar_mul_def_add(const Ta a, const Tb b) {
    return a + b;
}

#include <functional>
#include <iostream>
#include <typeinfo>

template<typename It1, typename It2, typename Type = Best_It_t(It1,It2)>
auto scalar_mul(
    It1 Ibeg,
    const It1 Iend,
    It2 I2,
    Type Init = Type(),
    typename std::function<Best_It_t(It1,It2)(It_t(It1), It_t(It2))> MulF =
        scalar_mul_def_mul<It_t(It1), It_t(It2)>,
    typename std::function<Best_t<Best_It_t(It1,It2),Type>
        (Best_t<Best_It_t(It1,It2),Type>, Best_It_t(It1,It2))> AddF =
        scalar_mul_def_add<Best_t<Best_It_t(It1,It2),Type>, Best_It_t(It1,It2)>
) {
    Best_t<Best_It_t(It1,It2), Type> scalar = Init;
    for(; Ibeg != Iend; ++Ibeg, ++I2) {
        auto x = MulF(*Ibeg, *I2);
        scalar = AddF(scalar, x);
    }
    return scalar;
}

//#define _SANYA_VERTOLET_TEST_
#ifdef _SANYA_VERTOLET_TEST_
#include <iostream>
#include <vector>
#include <array>
#include <list>

int main() {
    double v1[] { -1, 2, 3 };
    std::array<double, 3> v2 { 4.4, 5.5, 6.6 };
    auto res = scalar_mul(v1, v1+3, v2.begin());
    std::cout << res << std::endl;
}
#endif
