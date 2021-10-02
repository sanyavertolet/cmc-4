#include <string>
#include <iostream>

class BinaryNumber
{
public:
    BinaryNumber(const std::string &s) {
        str_ = s;
    }
    operator std::string () const {
        return str_;
    }
    const BinaryNumber &operator++() {
        int i = str_.length() - 1;
        bool is_overflowed = false;
        while(i >= 0 && str_[i] == '1') {
            if(i == 0) {
                is_overflowed = true;
            }
            str_[i] = '0';
            i--;
        }
        if(is_overflowed) {
            str_ = '1' + str_;
        } else {
            str_[i] = '1';
        }
        return *this;
    }
private:
    std::string str_;
};
