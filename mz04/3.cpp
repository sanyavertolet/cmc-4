#include <algorithm>
#include <vector>

void process(const std::vector<int> &v1, std::vector<int> &v2) {
    if(!v1.empty()) {
        std::vector<int> v;
        std::copy(v1.begin(), v1.end(), std::back_inserter(v));
        std::sort(v.begin(), v.end());
        auto last = std::unique(v.begin(), v.end());
        v.erase(last, v.end());
        auto v_it = v.begin();
        for(; *v_it < 0 && v_it < v.end(); ++v_it);
        auto dest_it = v2.begin();
        for(auto src_it = v2.begin(); src_it < v2.end(); ++src_it) {
            if(src_it - v2.begin() != *v_it) {
                *dest_it = *src_it;
                ++dest_it;
            } else {
                ++v_it;
            }
        }
        v2.resize(dest_it - v2.begin());
    }
}

//#define _TEST_
#ifdef _TEST_
#include <iostream>
int main() {
    std::vector<int> v1 = { 1, 2, 3 };
    std::vector<int> v2 = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    
    process(v1, v2);

    for(auto item : v2) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}
#endif
