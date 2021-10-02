
class Figure {
public:
    virtual bool equals(Figure* other) {
        return false;
    }
    virtual ~Figure() = default;

    enum class Type {
        NONE = 0,
        RECTANGLE = 2,
        TRIANGLE = 3
    };
    Type t_{Type::NONE};
};

class Rectangle : public Figure {
    int a_, b_;
public:
    Rectangle(int a, int b): a_(a), b_(b) {
        t_ = Type::RECTANGLE;
    }
    bool equals(Figure* other) override {
        if (!other || other->t_ != t_) {
            return 0;
        }
        auto t = (Rectangle *)other;
        return t->a_ == a_ && t->b_ == b_;
    }
};

class Triangle : public Figure {
    int a_, b_, c_;
public:
    Triangle(int a, int b, int c): a_(a), b_(b), c_(c) {
        t_ = Type::TRIANGLE;
    }
    bool equals(Figure* other) override {
        if (!other || other->t_ != t_) {
            return 0;
        }
        auto t = (Triangle *)other;
        return t->a_ == a_ && t->b_ == b_ && t->c_ == c_;
    }
};

//#define _TEST_
#ifdef _TEST_
#include <iostream>
#include <cassert>

int main()
{
    Figure *f1 = new Rectangle(2,3);
    Figure *f2 = new Rectangle(2,3);
    Figure *f3 = new Triangle(2,3,4);
    Figure *f4 = new Triangle(4,2,3);

    std::cout <<f1->equals(f2) <<std::endl;
    std::cout <<f1->equals(f3) <<std::endl;
    std::cout <<f3->equals(f1) <<std::endl;
    std::cout <<f3->equals(f4) <<std::endl;

    Rectangle r1(10, 5), r2(10, 2), r3(10, 5), r4(5, 10);
    Triangle t1(1, 2, 3);
    Figure *f = &r1;
    assert(!f->equals(&r2));
    assert(f->equals(&r3));
    assert(!f->equals(&r4));
    assert(!f->equals(&t1));
    assert(!f->equals(nullptr));
}
#endif//_TEST_
