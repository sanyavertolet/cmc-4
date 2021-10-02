#include <iostream>

int main() {
    char ch;
    std::string str;
    while(std::cin >> str) {
        bool is_one = true;
        bool was_beta = false;
        for(size_t i = 0; i < str.length(); ++i) {
            ch = str[i];
            if(ch == '3' || ch == '4') {
                if(was_beta) {
                    is_one = false;
                    break;
                }
            } else if(ch == '1' || ch == '2') {
                was_beta = true;
            } else {
                is_one = false;
                break;
            }
        }
        std::cout << is_one << std::endl;
    }
}
