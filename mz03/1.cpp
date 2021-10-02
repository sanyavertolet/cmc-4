#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <sstream>
#include <iomanip>

namespace numbers {
    class complex;
}

class numbers::complex {
public:
    complex(double re = 0, double im = 0) : re_(re), im_(im) {}
    explicit complex(std::string str) {
        size_t comma_pos;
        str = str.substr(1);
        re_ = std::stod(str, &comma_pos);
        im_ = std::stod(str.substr(comma_pos + 1));
    }
    double re() const { return re_; }
    double im() const { return im_; }
    double abs2() const { return re_ * re_ + im_ * im_; }
    double abs() const { return std::sqrt(abs2()); }
    const std::string to_string() const {
        constexpr int BUF_SIZE = 1024;
        char buf[BUF_SIZE];
        sprintf(buf, "(%.10g,%.10g)", re_, im_);
        return std::string(buf);
    }
    complex operator+=(const complex other) {
        re_ += other.re_;
        im_ += other.im_;
        return *this;
    }
    complex operator-=(const complex other) {
        re_ -= other.re_;
        im_ -= other.im_;
        return *this;
    }
    complex operator*=(const complex other) {
        double re = re_ * other.re_ - im_ * other.im_;
        double im = re_ * other.im_ + im_ * other.re_;
        re_ = re;
        im_ = im;
        return *this;
    }
    complex operator/=(const complex other) {
        double re = (re_ * other.re_ + im_ * other.im_) / other.abs2();
        double im = (im_ * other.re_ - re_ * other.im_) / other.abs2();
        re_ = re;
        im_ = im;
        return *this;
    }
    complex operator~() const {
        return complex(re_, -im_);
    }
    complex operator-() const {
        return complex(-re_, -im_);
    }
    void print() const {
        std::cout << to_string() << std::endl;
    }
private:
    double re_{};
    double im_{};
};

numbers::complex operator+(numbers::complex a, const numbers::complex b) {
    numbers::complex ret = a;
    ret += b;
    return ret;
}
numbers::complex operator-(numbers::complex a, const numbers::complex b) {
    numbers::complex ret = a;
    ret -= b;
    return ret;
}
numbers::complex operator*(numbers::complex a, const numbers::complex b) {
    numbers::complex ret = a;
    ret *= b;
    return ret;
}
numbers::complex operator/(numbers::complex a, const numbers::complex b) {
    numbers::complex ret = a;
    ret /= b;
    return ret;
}
