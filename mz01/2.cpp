#include <iostream>

class A
{
public:
    A() noexcept { std::cin >> num; };
    A(const A& a) noexcept : A()
    {
        num += a.num;
        to_print = true;
    }
    ~A() noexcept {
        if(to_print) {
            std::cout << num << std::endl;
        }
    }
    int num;
    bool to_print{false};
};
