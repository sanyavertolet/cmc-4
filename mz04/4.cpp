#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

class Sequence {
public:
    Sequence() : size_(0), average_(0.0), accumulator_({}), ignore_(0) {}
    void operator()(double item) {
        average_ += item / size_;
    }
    void get_sequence() {
        double tmp;
        while(std::cin >> tmp) {
            accumulator_.push_back(tmp);
        }
        size_ = accumulator_.size();
    }
    void get_average() {
        *this = std::for_each(accumulator_.begin() + ignore_, accumulator_.end() - ignore_, *this);
        std::cout << std::setprecision(10) << std::fixed << average_ << std::endl;
    }
    void normalize() {
        ignore_ += size_ / 10;
        std::sort(accumulator_.begin() + ignore_, accumulator_.end() - ignore_);
        size_ -= 2 * ignore_;
        int to_kick = size_ / 10.0;
        ignore_ += to_kick;
        size_ -= 2 * to_kick;
    }
private:
    size_t size_;
    double average_;
    std::vector<double> accumulator_;
    size_t ignore_;
};

int main() {
    Sequence seq;
    seq.get_sequence();
    seq.normalize();
    seq.get_average();
}
