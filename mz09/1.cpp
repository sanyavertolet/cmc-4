#include <iostream>
#include <string>

class Print {
public:
    Print(std::string str) : str_(str) {}
    ~Print() { std::cout << str_ << std::endl; }
private:
    std::string str_;
};

void recursion() {
    std::string str;
    if(!(std::cin >> str)) {
        throw 0;
    } 
    Print p(str);
    recursion();
}

int main() {
    try {
        recursion();
    } catch(...) { }
}
