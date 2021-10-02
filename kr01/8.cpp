#include <string>
#include <cinttypes>
std::string gen_power(uint32_t power) {
    if(!power) {
        return "1";
    }
    std::string variables;
    std::string operations;
    while(power) {
        if(power & 1) {
            operations = "*" + operations;
            variables += "x";
            --power;
        } else {
            operations = "!*" + operations;
            power >>= 1;
        }
    }
    operations.erase(0, 1);
    return variables + operations;
}

//#define _TEST_
#ifdef _TEST_
#include <iostream>
int main() {
    std::cout << "0:" << gen_power(0) << std::endl;
    std::cout << "1:" << gen_power(1) << std::endl;
    std::cout << "2:" << gen_power(2) << std::endl;
    std::cout << "3:" << gen_power(3) << std::endl;
    std::cout << "9:" << gen_power(9) << std::endl;
}
#endif 
