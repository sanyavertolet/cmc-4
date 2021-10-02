#include <cinttypes>
#include <vector>

void process(std::vector<int64_t> &vec, int64_t border) {
    if(!vec.empty()) {
        vec.reserve(2 * vec.size());
        auto end = vec.rend();
        for(auto it = vec.rbegin(); it < end; it++) {
            if(*it >= border) {
                vec.push_back(*it);
            }
        }
    }
}

//#define _TEST_
#ifdef _TEST_
#include <iostream>
int main() {
    std::vector<int64_t> v = {1, 2, 3, 4, 5, 6};
    int64_t border = 4;
    process(v, border);
    for(auto item : v) {
        std::cout << item << " ";
    }
    std::cout << std::endl;

}
#endif
