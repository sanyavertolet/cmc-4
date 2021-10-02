#include <iostream>

class S {
public:
    S(S &&other) {
        int num;
        if(std::cin >> num) {
            sum_ = num + other.sum_;
            flag_ = true;
            other.flag_ = false;
        } else {
            flag_ = false;
            other.flag_ = true;
        }
    }
    S() {
        flag_ = bool(std::cin >> sum_);
    }
    ~S() {
        if(flag_) {
            std::cout << sum_ << std::endl;
        }
    }
    operator bool() {
        return flag_;
    }
private:
    int sum_{};
    bool flag_{};
};

//#define _DEBUG_
#ifdef _DEBUG_
void func(S v) {
    if(v) {
        func(std::move(v));
    }
}

int main() {
    func(S());
}
#endif
