#include <iostream>
#include <algorithm>

int main() {
    int m, n;
    int r1, c1;
    int r2, c2;
    
    std::cin >> m >> n;

    while(std::cin >> r1 >> c1 >> r2 >> c2) {
        auto r_min = std::min(r1, r2);
        auto r_max = std::max(r1, r2);

        auto c_min = std::min(c1, c2);
        auto c_max = std::max(c1, c2);
    
        auto delta_r = std::min(r_max - r_min, r_min + m - r_max);
        auto delta_c = std::min(c_max - c_min, c_min + n - c_max);

        std::cout << delta_c + delta_r << std::endl;
    }
    return 0;
}
