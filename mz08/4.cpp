#include <iostream>
#include <string>
#include <string.h>
#include <stdexcept>

class String {
public:
    String() {}
    String(const char*);
    String(const std::string&);
    String(String &other);
    String(String &&other);
    ~String();

    size_t length() const;
    static constexpr size_t empty = size_t(-1);

    //operator const char*() const;
    operator const std::string() const;

    String& operator=(const char* c_str);
    String& operator=(String &other);
    String& operator=(String &&other);
    String& operator+=(const char*);
    String& operator+=(const String &other);

    const char& operator[](const size_t idx) const;
    char& operator[](const size_t idx);

    friend String operator+(const String&, const String&);

private:
    class Holder;
    Holder *holder_{nullptr};
};

class String::Holder {
public:
    Holder() {}
    Holder(const size_t);
    Holder(const char*);
    Holder(const char*, const char*);
    ~Holder() {if(c_str_) {delete[] c_str_;}}
    Holder* get_link() {
        ++nlinks_;
        return this;
    }
    void release_link() {
        --nlinks_;
        if(nlinks_ == 0) {
            delete this;
        }
    }
    const char* c_str() const {
        return c_str_;
    }
    char& c_str(size_t idx) {
        if(idx >= size_) {
            length(idx+1);
        }
        return c_str_[idx];
    }
    int nlinks() const {
        return nlinks_;
    }
    size_t length() const {
        return size_ - 1;
    }
    void length(const size_t length);
    void new_str(const char* c_str);
    void new_str(const char* c_str1, const char* c_str2);

private:
    char *c_str_{nullptr};
    size_t size_{0};
    size_t nlinks_{1};
};

void String::Holder::length(const size_t length) {
    size_t new_size = ((length + 1 + sizeof(int)-1)/sizeof(int)) * sizeof(int);
    size_t copy_len = std::min(length, size_-1);
    char* new_str = new char[new_size];
    if(c_str_) {
        ::memcpy(new_str, c_str_, copy_len);
        delete[] c_str_;
    }
    size_ = new_size;
    c_str_ = new_str;
    memset(&c_str_[copy_len], 0, new_size - copy_len);
}

String::Holder::Holder(const size_t len) {
    length(len);
}

void String::Holder::new_str(const char* c_str) {
    if(c_str_) {
        delete[] c_str_;
    }
    size_ = ::strlen(c_str) + 1;
    c_str_ = new char[size_];
    ::memcpy(c_str_, c_str, size_);
}

void String::Holder::new_str(const char* c_str1, const char* c_str2) {
    if(c_str_) {
        delete[] c_str_;
    }
    int l1 = ::strlen(c_str1);
    int l2 = ::strlen(c_str2);
    size_ = l1 + l2 + 1;
    c_str_ = new char[size_];
    memcpy(c_str_, c_str1, l1);
    memcpy(&c_str_[l1], c_str2, l2+1);
}

String::Holder::Holder(const char* c_str) {
    new_str(c_str);
}

String::Holder::Holder(const char* c_str1, const char* c_str2) {
    new_str(c_str1, c_str2);
}

//String methods

String::String(const char* c_str) {
    holder_ = new String::Holder(c_str);
}

String::String(const std::string& str) {
    holder_ = new String::Holder(str.c_str());
}

String::String(String& other) {
    if(this != &other) {
        if(other.holder_) {
            holder_ = other.holder_->get_link();
        }
    }
}

String::String(String &&other) {
    holder_ = other.holder_;
    other.holder_ = nullptr;
}

String::~String() {
    if(holder_ != nullptr) {
        holder_->release_link();
    }
}

String::operator const std::string() const {
    if(holder_ != nullptr) {
        return std::string(holder_->c_str());
    } else {
        return std::string{};
    }
}

String& String::operator=(const char* c_str) {
    if(holder_ != nullptr) {
        if(holder_->nlinks() > 1) {
            holder_->release_link();
            holder_ = new String::Holder(c_str);
        } else {
            holder_->new_str(c_str);
        }
    } else {
        holder_ = new String::Holder(c_str);
    }
    return *this;
}

String& String::operator=(String &other) {
    if(&other != this) {
        if(holder_ != nullptr) {
            holder_->release_link();
        }
        if(other.holder_) {
            holder_ = other.holder_->get_link();
        } else {
            holder_ = nullptr;
        }
    }
    return *this;
}

String& String::operator=(String&& other) {
    if(&other != this) {
        if(holder_) {
            holder_->release_link();
        }
        holder_ = other.holder_;
        other.holder_ = nullptr;
    }
    return *this;
}

size_t String::length() const {
    if(holder_ != nullptr) {
        return holder_->length();
    }
    return empty;
}

String& String::operator+=(const char* c_str) {
    if(c_str != nullptr) {
        if(holder_ != nullptr) {
            if(holder_->nlinks() > 1) {
                String::Holder *new_holder =
                    new String::Holder(holder_->c_str(), c_str);
                holder_->release_link();
                holder_ = new_holder;
            } else {
                holder_->new_str(holder_->c_str(), c_str);
            }
        } else {
            holder_ = new String::Holder(c_str);
        }
    }
    return *this;
}

String& String::operator+=(const String& other) {
    if(other.holder_ != nullptr) {
        if(holder_ != nullptr) {
            String::Holder *new_holder =
                new String::Holder(holder_->c_str(), other.holder_->c_str());
            holder_->release_link();
            holder_ = new_holder;
        } else {
            holder_ = other.holder_->get_link();
        }
    }
    return *this;
}

char& String::operator[](const size_t idx) {
    if(holder_ == nullptr) {
        holder_ = new String::Holder(idx+2);
    } else if(holder_->nlinks() > 1) {
        auto new_holder = new String::Holder(holder_->c_str());
        holder_->release_link();
        holder_ = new_holder;
    }
    if(idx >= holder_->length()) {
        holder_->length(idx+1);
    }
    return holder_->c_str(idx);
}

const char& String::operator[](const size_t idx) const {
    if(holder_ == nullptr) {
        static char zero = 0;
        return zero;
    }
    return holder_->c_str(idx);
}

String operator+(const String& s1, const String& s2) {
    String s0(s1);
    s0 += s2;
    return s0;
}

//#define __STRING_DEBUG__
#ifdef __STRING_DEBUG__

int main() {
    String a = std::string("abcdef");
    char s[] {"hello"};
    String b(s);
    String c(std::string("56789"));
    c = std::string("12345");
    c = s;
    c += std::string("uvwxyz");
    std::cout << std::string(c) <<std::endl;
    String d = a; // в памяти хранится "abc" в одном экземпляре
    c = a;
    d += "+=aaa"; // для b создался новый "массив" символов.

    c[1] = c[2] = 'w';

    String z;
    if(z.length() == String::empty) {
        std::cout <<"String z iz empty" <<std::endl;
    }
    for(int j = 0; c[j] != 0; ++j) {
        std::cout <<c[j];
        std::cout <<std::endl;
        z[j] = c[j];
    }
    std::cout <<"z = " <<std::string(z) <<std::endl;


    String zz = String("abc") + "+11" + "+jhghg";
    std::cout <<"zz = " <<std::string(zz) <<std::endl;

    return 0;
}

#endif//__STRING_DEBUG__
