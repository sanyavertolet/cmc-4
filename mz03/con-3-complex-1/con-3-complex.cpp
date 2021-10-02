#include "complex.h"

namespace numbers {

complex::complex(const complex& other)
{
    if (this == &other)
        return;

    this->re_ = other.re_;
    this->im_ = other.im_;
std::cout <<"    NEW complex " <<(void*)this << " <= (" <<re_ <<"," <<im_ <<")" <<std::endl;
}

complex::complex(double re, double im){
    re_ = re;
    im_ = im;
std::cout <<"    NEW complex " <<(void*)this << " (" <<re <<"," <<im <<")" <<std::endl;
}

complex::complex(std::string str) {
    size_t comma_pos;
    re_ = std::stod(str.substr(1), &comma_pos);
    im_ = std::stod(str.substr(comma_pos + 2));
std::cout <<"    NEW complex " <<(void*)this << " \"" <<str <<"\"" <<std::endl;
}

complex::~complex() {
std::cout << "    del complex " << (void*)this << " (" <<re_ <<"," <<im_ <<")" <<std::endl;
}

std::string complex::to_string() const
{
    constexpr int BUF_SIZE = 1024;
    char buf[BUF_SIZE];
    sprintf(buf, "(%.10g,%.10g)", re_, im_);
    return std::string(buf);
}

double complex::abs2() const
{
    return re_ * re_ + im_ * im_;
}

double complex::abs() const
{
    return std::sqrt(complex::abs2());
}

complex& complex::operator=(const complex& other)
{
    if (this == &other)
        return *this;

    re_ = other.re_;
    im_ = other.im_;

    return *this;
}

complex& complex::operator+=(const complex& other)
{
    re_ += other.re_;
    im_ += other.im_;
    return *this;
}

complex& complex::operator-=(const complex& other)
{
    re_ -= other.re_;
    im_ -= other.im_;
    return *this;
}

complex& complex::operator*=(const complex& other)
{
    double re = re_ * other.re_ - im_ * other.im_;
    double im = re_ * other.im_ + im_ * other.re_;
    re_ = re;
    im_ = im;
    return *this;
}

complex& complex::operator/=(const complex& other)
{
    double re = (re_ * other.re_ + im_ * other.im_) / other.abs2();
    double im = (im_ * other.re_ - re_ * other.im_) / other.abs2();
    re_ = re;
    im_ = im;
    return *this;
}

complex complex::operator~() const
{
    return complex(re_, -im_);
}

complex complex::operator-() const
{
    return complex(-re_, -im_);
}

void complex::print(std::string pref) const
{
    if(!pref.empty()) {
        std::cout << pref;
    }
    std::cout <<complex::to_string();
    if(!pref.empty()) {
        std::cout <<std::endl;
    }
}

complex operator+(const complex& a, const complex& b)
{
    complex ret = a;
    ret += b;
    return ret;
}

complex operator-(const complex& a, const complex& b)
{
    complex ret = a;
    ret -= b;
    return ret;
}

complex operator*(const complex& a, const complex& b) {
    complex ret = a;
    ret *= b;
    return ret;
}

complex operator/(const complex& a, const complex& b) {
    complex ret = a;
    ret /= b;
    return ret;
}

} //namespace numbers
