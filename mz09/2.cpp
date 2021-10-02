#include <iostream>
#include <cinttypes>

class Result {
public:
    Result(int64_t value) : value_(value) { throw(*this); }
    int64_t value() { return value_; }
private:
    int64_t value_;
};

int64_t func(int64_t a, int64_t b, uint32_t k) {
    if(k == 0) {
        Result result(a + b);
    } else if(k > 0 && b == 1) {
        Result result(a);
    } else if(k > 0 && b > 1) {
        try {
            func(a, b - 1, k);
        } catch (Result new_b) {
            func(a, new_b.value(), k - 1);
        }
    }
    return 1;
}

int main() {
    int64_t a;
    int64_t b;
    uint32_t k;
    while(std::cin >> a >> b >> k) {
        try {
            func(a, b, k);
        } catch(Result result) {
            std::cout << result.value() << std::endl;
        }
    }
}
