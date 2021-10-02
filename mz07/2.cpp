#include <string>
#include <sstream>
class Rectangle : Figure {
public:
    Rectangle(double a = 0, double b = 0) : a_(a), b_(b) {}
    double get_square() const override { return a_ * b_; }
    static Rectangle* make(std::string);
private:
    double a_, b_;
};

Rectangle* Rectangle::make(std::string str) {
    std::stringstream strstr(str);
    double a, b;
    strstr >> a >> b;
    return new Rectangle(a, b);
}

class Square : Figure {
public:
    Square(double a) : a_(a) {}
    double get_square() const override { return a_ * a_; }
    static Square* make(std::string);
private:
    double a_;
};

Square* Square::make(std::string str) {
    std::stringstream strstr(str);
    double a;
    strstr >> a;
    return new Square(a);
}

#include <cmath>
class Circle : Figure {
public:
    Circle(double a) : a_(a) {}
    double get_square() const override { return M_PI * a_ * a_; }
    static Circle* make(std::string);
private:
    double a_;
};

Circle* Circle::make(std::string str) {
    std::stringstream strstr(str);
    double a;
    strstr >> a;
    return new Circle(a);
}
