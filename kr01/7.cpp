#include <iostream>

bool A() {
    char ch;
    bool is_ok = true;
    std::cin >> ch;
    if (ch == 'c') {
        is_ok = A();
        std::cin >> ch;
        if (ch != 'd') {
            return false;
        }
    } else if (ch != 'e') {
        return false;
    }
    return is_ok;
}

bool B() {
    char ch;
    bool is_ok = true;
    if (std::cin >> ch) {
        if (ch == 'b') {
            is_ok = B();
        } else if (ch != 'd') {
            return false;
        }
    }
    return is_ok;
}

bool S() {
    bool is_a_ok = true;
    bool is_b_ok = true;
    char ch;
    std::cin >> ch;
    if (ch == 'a') {
        is_a_ok = A();
        std::cin >> ch;
        if (ch != 'b') {
            return false;
        }
    } else if (ch == 'c') {
        is_b_ok = B();
    }
    return is_a_ok || is_b_ok;
}


int main() {
    if(S()) {
        std::cout << 1 << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
    return 0;
}
