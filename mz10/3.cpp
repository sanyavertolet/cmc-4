//L1 = { a^n0^mb^n1^m | n, m > 0 }
//S = XY
//X = aXC | aC
//Y = BY1 | B1
//CB = BC
//aB = a0
//0B = 00
//C1 = b1
//Cb = bb
#include <iostream>
#include <string>

enum {
    ENDLINE = ' ', //Конец строки
    ENDFILE = -1 //Конец файла
};

int stri(bool next_line = false) {
    static bool is_ws = true;
    char ch;
    std::cin >>std::noskipws;
    if(is_ws) {
        if(next_line) {
            while(std::cin >> ch) {
                if(!::isspace(int(ch))) {
                    is_ws = false;
                    return ch;
                }
            }
            return ENDFILE;
        } else {
            return ENDLINE;
        }
    }
    if(std::cin >> ch) {
        if(::isspace(int(ch))) {
            is_ws = true;
            return ENDLINE;
        } else {
            is_ws = false;
            return ch;
        }
    }
    is_ws = true;
    return ENDLINE;
}

int main() {
    int ch = 0;
    while((ch = stri(true)) != ENDFILE) {
        bool is_ok = true;
        int n;
        for(n = 0; ch == 'a'; ++n, ch = stri());
        if(n == 0) {
            is_ok = false;
        }
        int m;
        for(m = 0; ch == '0' && is_ok; ++m, ch = stri());
        if(m == 0) {
            is_ok = false;
        }
        int i;
        for(i = 0; ch == 'b' && is_ok; ++i, ch = stri());
        if(i != n) {
            is_ok = false;
        }
        for(i = 0; ch == '1' && is_ok; ++i, ch = stri());
        if(i != m) {
            is_ok = false;
        }
        if(ch != ENDLINE) {
            is_ok = false;
        }
        std::cout << is_ok << std::endl;
        for(; ch != ENDLINE ; ch = stri());
    }
}
