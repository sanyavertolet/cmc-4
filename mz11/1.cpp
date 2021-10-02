#include <iostream>
#include <string>
#include <regex>

bool check_ns(const std::string &l, const std::string &r, bool &S_, bool &rS) {
    if(r == "_") {
        if(l == "S") {
            S_ = true;
        } else {
            return false;
        }
    }
    if(!rS) {
        if(r.find('S') != std::string::npos) {
            rS = true;
        }
    }
    if(rS && S_) {
        return false;
    }
    return l.size() <= r.size();
}

bool check_left(const std::string &l, const std::string &r) {
    if(r == "_") {
        return true;
    }
    static const std::regex expr("[A-Z]?[a-z0-9]*");
    return std::regex_match(r, expr);
}

bool check_right(const std::string &l, const std::string &r) {
    if(r == "_") {
        return true;
    }
    static const std::regex expr("[a-z0-9]*[A-Z]?");
    return std::regex_match(r, expr);
}

bool check_left_auto(const std::string &l, const std::string &r, bool &SN) {
    if(l == "S" && r == "_") {
        return true;
    }
    if(l == "S" && !SN) {
        static const std::regex expr("[A-Z]");
        if(std::regex_match(r, expr)) {
            SN = true;
            return true;
        }
    }
    static const std::regex expr("[A-Z]?[a-z0-9]");
    return std::regex_match(r, expr);
}

bool check_right_auto(const std::string &l, const std::string &r, bool &SN) {
    if(l == "S" && r == "_") {
        return true;
    }
    if(l == "S" && !SN) {
        static const std::regex expr("[A-Z]");
        if(std::regex_match(r, expr)) {
            SN = true;
            return true;
        }
    }
    static const std::regex expr("[a-z0-9][A-Z]?");
    return std::regex_match(r, expr);
}

int main() {
    bool is_ns = true;
    bool is_l = true;
    bool is_la = true;
    bool is_r = true;
    bool is_ra = true;
    bool s_ = false;
    bool rs = false;
    bool la_sn = false;
    bool ra_sn = false;
    std::string l, r;
    while(std::cin >> l >> r) {
        is_ns &= check_ns(l, r, s_, rs);
        if(s_ && rs) {
            is_la = false;
            is_ra = false;
        }
        if(is_l) {
            is_l = check_left(l, r);
            if(!is_l) {
                is_la = false;
            }
            if(is_la) {
                is_la = check_left_auto(l, r, la_sn);
            }
        }
        if(is_r) {
            is_r = check_right(l, r);
            if(!is_r) {
                is_ra = false;
            }
            if(is_ra) {
                is_ra = check_right_auto(l, r, ra_sn);
            }
        }
    }
    if(is_la) {
        if(!s_ && la_sn) {
            is_la = false;
        }
    }
    if(is_ra) {
        if(!s_ && ra_sn) {
            is_ra = false;
        }
    }
    int type = 2;
    if(is_l) {
        if(is_la) {
            type = 311;
        } else {
            type = 31;
        }
    } else if(is_r) {
        if(is_ra) {
            type = 321;
        } else {
            type = 32;
        }
    } else if(is_ns) {
        type = 21;
    }
    std::cout << type << std::endl;
}
