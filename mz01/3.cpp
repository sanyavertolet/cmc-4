#include <iostream>

int main() {
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    unsigned char c;
    bool is_zero = false;
    bool is_num = false;
    std::cin >> std::noskipws;
    while(std::cin >> c) {
        if('1' <= c && c <= '9') {
            is_zero = false;
            is_num = true;
            std::cout << c;
        } else if(c == '0') {
            if(!is_num) {
                is_zero = true;
            } else {
                std::cout << c;
            }
        } else {
            is_num = false;
            if(is_zero) {
                is_zero = false;
                std::cout << "0";
            }
            std::cout << c;
        }
    }
    if(is_zero) {
        std::cout << '0';
    }
    return 0;
}
