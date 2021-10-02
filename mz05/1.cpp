template<typename Container>
typename Container::value_type process(Container c) {
    auto it = c.rbegin();
    typename Container::value_type counter{};
    for(int i = 0; i < 3 && it != c.rend(); i++, it++) {
        counter += *it;
        it++;
        if(it == c.rend()) {
            break;
        }
    }
    return counter;
}


//#define _TEST_
#ifdef _TEST_
#include <vector>
#include <iostream>
int main() {
    std::vector<int> v = {1, 2, 4, 5};
    std::cout << process(v) << std::endl;
}
#endif
