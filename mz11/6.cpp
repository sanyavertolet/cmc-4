#include <iostream>
#include <utility>
#include <string>
#include <map>

using Anext = std::map<char,std::string>;
using Auto = std::map<std::string, Anext>;

int main() {
    Auto a;
    std::string name;

    a[   "H"]['0'] = "A";
    a[   "H"]['1'] = "AB";
    a[   "A"]['0'] = "A";
    a[   "A"]['1'] = "AB";
    a[  "AB"]['0'] = "AC";
    a[  "AB"]['1'] = "ABC";
    a[  "AC"]['0'] = "AS";
    a[  "AC"]['1'] = "ABS";
    a[ "ABC"]['0'] = "ACS";
    a[ "ABC"]['1'] = "ABCS";
    a[  "AS"]['0'] = "A";
    a[  "AS"]['1'] = "AB";
    a[ "ABS"]['0'] = "AC";
    a[ "ABS"]['1'] = "ABC";
    a[ "ACS"]['0'] = "AS";
    a[ "ACS"]['1'] = "ABS";
    a["ABCS"]['0'] = "ACS";
    a["ABCS"]['1'] = "ABCS";

    a[  "AS"][0] = "";
    a[ "ABS"][0] = "";
    a[ "ACS"][0] = "";
    a["ABCS"][0] = "";

    const auto &astart_it = a.find("H");

    std::string str;
    while(std::cin >>str) {
        if(str == "q") {
            break;
        }
        int nsteps = 0;
        Anext *anext = &astart_it->second;
        name = astart_it->first;
        bool res = false;

        for(char ch: str) {
            const auto &next_it = anext->find(ch);
            if(next_it == anext->end()) {
                goto False;
            }
            name = next_it->second;
            const auto &anext_it = a.find(name);
            if(anext_it == a.end()) {
                std::cerr <<"Input error: state " <<name <<" not found" <<std::endl;
                return 1;
            }
            anext = &anext_it->second;
            ++nsteps;
        }
        if(anext->find(0) != anext->end()) {
            res = true;
        }
False:  std::cout <<res <<std::endl;
    }
    return 0;
}
