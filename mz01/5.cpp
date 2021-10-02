#include <iostream>
#include <iomanip>

int main() {
    unsigned buf;
    constexpr unsigned shift = 8;
    constexpr int n = 4;
    std::cin >> std::hex;
    while(std::cin >> buf) {
        for(int i = 0; i < n; i++) {
            unsigned number = 0;
            for(int j = 0; j < n; j++) {
                if(std::cin >> buf) {
                    number <<= shift;
                    number += buf;
                } else {
                    return 0;
                }
            }
            std::cout << number << std::endl;
        }
    }
}
