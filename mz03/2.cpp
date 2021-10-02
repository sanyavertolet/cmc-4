namespace numbers {
    class complex_stack;
}

class numbers::complex_stack {
public:
    complex_stack() : size_(0), ptr_(nullptr) {}
    complex_stack(const complex_stack& other, size_t size = 0) : size_(size) {
        if(&other == this) {
            return;
        }
        if(size_ == 0) {
            size_ = other.size_;
        }
        ptr_ = new numbers::complex[size_];
        if(ptr_ != nullptr) {
            for(size_t i = 0; i < std::min(size_, other.size()); i++) {
                ptr_[i] = other.ptr_[i];
            }
        } else {
            size_ = 0;
        }
    }
    ~complex_stack() {
        if(ptr_ != nullptr) {
            delete [] ptr_;
        }
    }
    complex_stack operator=(const complex_stack &other) {
        if(this == &other) {
            return other;
        }
        if(ptr_ != nullptr) {
            delete [] ptr_;
        }
        ptr_ = new numbers::complex[other.size_];
        for(size_t i = 0; i < other.size_; i++) {
            ptr_[i] = other.ptr_[i];
        }
        size_ = other.size_;
        return *this;   
    }
    size_t size() const { return size_; }
    numbers::complex operator[](size_t index) const { return ptr_[index]; }
    complex_stack operator<<(numbers::complex to_add) const {
        complex_stack new_stack(*this, size_ + 1);
        new_stack.ptr_[size_] = to_add;
        return new_stack;
    }
    numbers::complex operator+() const { return ptr_[size_ - 1]; }
    complex_stack operator~() const { return complex_stack(*this, size_ - 1); }
private:
    size_t size_;
    numbers::complex *ptr_;
};
