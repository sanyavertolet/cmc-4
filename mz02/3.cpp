class C {
public:
    C(int i) {}
    C(double d) {}
    C(const C* ptr) {}
    C(C& p, C c) {}
    C() = default;
    int operator~() const { return 0; }
    C& operator&() { return *this; }
    C operator=(double p2) { return *this;}
    C& operator++() { return *this; }
    double operator* (C *ptr) { return 0; }
    friend C& operator+(int a, const C& c) { return &C(); }
};
