#include <vector>
#include <functional>
#include <iterator>
template<typename It, typename Function>
void myapply(It from, It to, Function f) {
    for(; from != to; ++from) {
        f(*from);
    }
}

template<typename It, typename Functor>
auto myfilter2(It begin, It end, Functor pred) {
    std::vector<std::reference_wrapper<typename std::iterator_traits<It>::value_type>> v;
    for(auto it = begin; it != end; it++) {
        if(pred(*it)) {
            v.push_back(std::ref(*it));
        }
    }
    return v;
}

//#define _TEST_
#ifdef _TEST_
#include <iostream>
template<typename Type>
bool pref(Type item) {
    return item < 0;
}
template<typename Type>
void f(Type& item) {
    item = -item;
}
template<typename Container>
void print(Container c) {
    for(auto item : c) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}
int main() {
    using Type = int;
    std::vector<Type> v = { -1, -5, -10, 0, 1, 2, 3, 4 };
    auto new_v = myfilter2(v.begin(), v.end(), pref<Type>);
    myapply(new_v.begin(), new_v.end(), f<Type>);
    print(v);
}
#endif
