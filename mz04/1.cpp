#include <vector>
#include <cinttypes>

void process(const std::vector<uint64_t> &src, std::vector<uint64_t> &dest, int step) {
    auto dest_rit = dest.rbegin();
    for(auto src_it = src.begin(); src_it < src.end() && dest_rit != dest.rend();
            ++dest_rit, src_it += step) {
        *dest_rit += *src_it;
        if(std::distance(src_it, src.end()) < step) {
            return;
        }
    }
}
//#define _TEST_
#ifdef _TEST_
#include <iostream>
int main() {
    std::vector<uint64_t> v1 = {1, 2, 3, 4, 5};
    std::vector<uint64_t> v2 = {0, 0, 0, 0, 0};
    int step = 3;
    process(v1, v2, step);
    for(auto num : v2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

}
#endif
