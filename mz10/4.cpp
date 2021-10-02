#include <iostream>

void print_k(int k) {
    if(k > 0) {
        std::cout << "b";
        print_k(k - 1);
        std::cout << "c";
    }
}

void print_n(int k, int i) {
    std::cout << "a";
    if(i > 0) {
        print_n(k - 2, i - 1);
    } else {
        print_k(k / 2);
    }
    std::cout << "d";
}

void pseudo_cycle(int k, int i) {
    print_n(k - 2, i - 1);
    std::cout << std::endl;
    if(i - 1 > 0) {
        pseudo_cycle(k, i - 1);
    }
    
}

int main() {
    int k;
    std::cin >> k;
    if(k % 2 != 0 || k < 4) {
        return 0;
    }
    pseudo_cycle(k, k / 2 - 1);
}
