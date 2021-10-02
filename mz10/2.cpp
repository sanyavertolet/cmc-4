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
        int k;
        for(k = 0; ch == '0'; ++k, ch = stri());
        if(k == 0) {
            is_ok = false;
            goto PRINT;
        }
        int m;
        for(m = 0; ch == '1'; ++m, ch = stri());
        if(m == 0) {
            is_ok = false;
        }
        else if(ch != '0' && ch != ENDLINE) {
            is_ok = false;
        } else {
            while(ch != ENDLINE) {
                int j;
                for(j = 0; j < k; ++j, ch = stri()) {
                    if(ch != '0') {
                        is_ok = false;
                        goto PRINT;
                    }
                }
                for(j = 0; j < m; ++j, ch = stri()) {
                    if(ch != '1') {
                        is_ok = false;
                        goto PRINT;
                    }
                }
            }
        }
PRINT:  std::cout << is_ok << std::endl;
        for(; ch != ENDLINE ; ch = stri());
    }
}
