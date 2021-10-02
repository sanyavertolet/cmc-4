#include <iostream>

int main() {
    constexpr int MAX_LEN = 4;
    int counter = 0;
    unsigned char ch;
    unsigned char last_ch = -1;
    while(std::cin >> std::noskipws >> ch) {
        if(ch == last_ch) {
            counter++;
        } else if(counter > MAX_LEN || last_ch == '#'){
            std::cout << '#' << last_ch << std::hex << counter << '#';
            counter = 1;
            last_ch = ch;
        } else {
            while(counter > 0) {
                std::cout << last_ch;
                --counter;
            }
            last_ch = ch;
            counter = 1;
        }
    }
    if(counter > MAX_LEN || last_ch == '#'){
        std::cout << '#' << last_ch << std::hex << counter << '#';
    } else {
        while(counter > 0) {
            std::cout << last_ch;
            --counter;
        }
    }
}
