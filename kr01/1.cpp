#include <cinttypes>
#include <vector>
void process(std::vector<uint64_t> &v, uint32_t s) {
    if (!v.empty()) {
        uint64_t sum = 0;
        for (auto item : v) {
            sum += item;
        }
        uint32_t to_add = v.size() / s;
        v.resize(v.size() + to_add);
        for(size_t right = v.size() - 1, left = right - to_add; left != 0 &&
                right >= s; --right, --left) {
            if ((left + 1) % s) {
                v[right] = v[left];
            } else {
                v[right] = sum;
                right--;
                v[right] = v[left];
            }
            sum -= v[left];
        }
    }
}

//#define _TEST_
#ifdef _TEST_
#include <iostream>
int main() {
    std::vector<uint64_t> v{2, 3, 4, 5, 6};
    process(v, 2);
    for(auto item : v) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}
#endif
