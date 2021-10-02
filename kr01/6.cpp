#include <iostream>
#include <utility>
#include <string>
#include <map>

using Anext = std::map<char, std::string>;
using Auto = std::map<std::string, Anext>;

int main() {
    Auto a;
    std::string name;
    a[   "S"]['a'] = "AB";
    a[  "AB"]['a'] = "S";
    a[  "AB"]['b'] = "E";
    a[  "AB"]['c'] = "BC";
    a[  "BC"]['a'] = "SE";
    a[  "BC"]['b'] = "B";
    a[  "SE"]['a'] = "AB";
    a[   "B"]['a'] = "S";
    a[   "E"][0] = "";
    a[  "SE"][0] = "";

    const auto &astart_it = a.find("S");

    std::string str;
    while(std::cin >> str) {
        Anext *anext = &astart_it->second;
        name = astart_it->first;
        bool res = false;
        for(char ch : str) {
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
        }
        if(anext->find(0) != anext->end()) {
            res = true;
        }
False:  std::cout << res << std::endl;
    }
    return 0;
}


