#include "complex.h"

namespace numbers {

complex_stack::complex_stack()
{
    ptr_ = nullptr;
    size_ = 0;
    tmp_ = false;
std::cout << "    NEW complex_stack " << (void*)this << "[]: " << (void*)ptr_ << std::endl;
}

complex_stack::complex_stack(complex_stack& other, size_t size)
{
    if(size == (size_t)-1) {
        size_ = other.size();
    } else {
        size_ = size;
    }
std::cout <<"    NEW complex_stack " <<(void*)this <<"[" <<size_ <<"]: " <<std::endl;

    if(other.tmp_ && size_ == other.size_) {
        ptr_ = other.ptr_;
        other.ptr_ = nullptr;
        other.size_ = 0;
        delete &other;
    } else {
        ptr_ = new complex[size_];
        if(ptr_ != nullptr) {
            size_t n = std::min(size_, other.size());
            for(size_t i = 0; i < n; i++) {
                ptr_[i] = other.ptr_[i];
            }
        } else {
            size_ = 0;
        }
    }
    tmp_ = false;
    std::cout << "        ptr_ " <<(void*)ptr_ <<std::endl;
}

complex_stack::~complex_stack() {
std::cout << "    del complex_stack " << (void*)this << "[" << size_ << "]: " << (void*)ptr_ << std::endl;
    delete [] ptr_;
}

complex& complex_stack::operator[](const size_t index)
{
    return ptr_[size_ - index - 1];
}

complex_stack& complex_stack::operator<<(const complex& to_add)
{
    complex_stack *new_stack = new complex_stack (*this, size_ + 1);
    new_stack->ptr_[size_] = to_add;
    new_stack->tmp_ = true;
    if(this->tmp_) {
        delete this;
    }
    return *new_stack;
}

complex_stack& complex_stack::operator~()
{
    complex_stack *new_stack = new complex_stack (*this, size_ - 1);
    new_stack->tmp_ = true;
    if(this->tmp_) {
        delete this;
    }
    return *new_stack;
}

complex_stack& complex_stack::operator=(complex_stack& other)
{
    if (this == &other)
        return *this;

    if(other.tmp_) {
        delete[] ptr_;
        ptr_ = other.ptr_;
        size_ = other.size_;
        other.ptr_ = nullptr;
        other.size_ = 0;
        delete &other;
    } else {
        if(size_ != other.size_) {
            delete [] ptr_;
            ptr_ = nullptr;
            size_ = 0;
            if(other.size_ > 0) {
                ptr_ = new complex[other.size_];
                if(ptr_ != nullptr) {
                    size_ = other.size_;
                }
            }
        }
        for(size_t i = 0; i < size_; i++) {
            ptr_[i] = other.ptr_[i];
        }
    }

    return *this;
}

complex& complex_stack::operator+() const
{
    return ptr_[size_ - 1];
}

void complex_stack::print(std::string pref) const
{
    if(!pref.empty()) {
        std::cout <<pref;
    }
    std::cout <<"[" <<size_ <<"]={";
    for(size_t i = 0; i < size_; i++) {
        std::cout <<"[" <<i <<"]=";
        ptr_[i].print();
        if(i < size_ - 1) {
            std::cout <<", ";
        }
    }
    std::cout <<"}";
    if(!pref.empty()) {
        std::cout <<std::endl;
    }
}

} //numbers
