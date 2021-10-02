#ifndef __COMPLEX_H__
#define __COMPLEX_H__

#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
#include <sstream>
#include <iomanip>

#include <vector>

namespace numbers {

class complex {
public:
    complex(const complex& other);
    complex(double re = 0.0, double im = 0.0);
    explicit complex(std::string str);
    ~complex();
    double re() const { return re_; }
    double im() const { return im_; }
    double abs2() const;
    double abs() const;
    std::string to_string() const;
    complex& operator=(const complex& other);
    complex& operator+=(const complex& other);
    complex& operator-=(const complex& other);
    complex& operator*=(const complex& other);
    complex& operator/=(const complex& other);
    complex operator~() const;
    complex operator-() const;
    void print(const std::string pref = {}) const;
private:
    double re_;
    double im_;
};

complex operator+(const complex& a, const complex& b);
complex operator-(const complex& a, const complex& b);
complex operator*(const complex& a, const complex& b);
complex operator/(const complex& a, const complex& b);

class complex_stack {
public:
    complex_stack();
    complex_stack(complex_stack& other, size_t size = (size_t)-1);
    ~complex_stack();
    size_t size() const { return size_; }
    complex& operator[](const size_t index);
    complex_stack& operator<<(const complex& to_add);
    complex_stack& operator~();
    complex_stack& operator=(complex_stack& other);
    complex& operator+() const;
    void print(std::string pref = {}) const;
private:
    complex *ptr_;
    size_t size_;
    bool tmp_;
};

complex eval(const std::vector<std::string> &args, const complex &z);

} //numbers::

#endif /* __COMPLEX_H__ */
