#include <iostream>
#include <cctype>

bool check_S(std::string right) {
    for(size_t i = 0; i < right.size(); ++i) {
        if(right[i] == 'S') {
            return true;
        }
    }
    return false;
}

bool check_onlyS(std::string &left) {
    return left == "S";
}
bool check_onlyT(std::string &left) {
    for(size_t i = 0; i < left.size(); ++i) {
        if(!(islower(int(left[i])) || isdigit(int(left[i])))) {
            return false;
        }
    }
    return true;
}
bool check_nounderline(std::string &left) {
    for(size_t i = 0; i < left.size(); ++i) {
        if(left[i] == '_') {
            return false;
        }
    }
    return true;
}
bool check_cf(std::string &left) {
    return left.size() == 1u;
}
bool check_space(std::string &right) {
    return right == "_";
}
bool check_exception(std::string &left, std::string &right) {
    return check_onlyS(left) && check_space(right);
}
bool check_decreasing(std::string &left, std::string &right) {
    if(check_space(right) && !check_onlyS(left)) {
        return true;
    }
    return left.size() > right.size();
}

int main() {
    std::string left;
    std::string right;
    bool is_rightS = false;
    bool is_cf = true;
    bool is_decreasing = false;
    bool is_nounderline = true;
    bool is_onlyT = false;
    bool rules_exist = false;
    bool is_onlyS = false;
    bool is_exception = false;
    while(std::cin >> left >> right) {
        rules_exist = true;
        is_cf &= check_cf(left);
        is_rightS |= check_S(right);
        is_decreasing |= check_decreasing(left, right);
        is_nounderline &= check_nounderline(left);
        is_onlyT |= check_onlyT(left);
        is_onlyS |= check_onlyS(left);
        is_exception |= check_exception(left, right);
    }
    
    if(!rules_exist || is_onlyT || !is_onlyS) {
        std::cout << -1 << std::endl;
    } else if(is_cf) {
        if(is_decreasing || (is_exception && is_rightS)) {
            std::cout << 2 << std::endl;
        } else {
            std::cout << 23 << std::endl;
        }
    } else {
        std::cout << 10 << std::endl;
    }
    
    //S _             //exception
    //S SA            //not working
    //A a

}
