class Sum
{
public:
    using int_t = int;
    Sum(int_t a, int_t b) : sum_{a + b} {}
    Sum(Sum s, int_t a) : sum_{s.get() + a} {}
    int_t get() const { return sum_; }
private:
    int_t sum_;
};
