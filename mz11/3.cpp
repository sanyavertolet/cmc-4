#include <iostream>
#include <utility>
#include <string>
#include <map>

using Anext = std::map<char, std::string>;
using Auto = std::map<std::string, Anext>;

int main() {
    Auto a;
    std::string name;

    while(std::cin >> name) {
        if(name == "END") {
            break;
        }
        std::string act;
        std::string dest;
        if(std::cin >> act >> dest) {
            auto &astate = a[name];
            char a = act[0];
            astate[a] = dest;
        }
    }

    while(std::cin >>name) {
        if(name == "END") {
            break;
        }
        auto &astate = a[name];
        astate[0] = "";
    }

    std::cin >> name;
    const auto &astart_it = a.find(name);
    if(astart_it == a.end()) {
        std::cout << 0 << std::endl << 0 << std::endl <<  name << std::endl;
        return 1;
    }
    std::string str;
    if(std::cin >> str) {
        int nsteps = 0;
        Anext *anext = &astart_it->second;
        name = astart_it->first;
        bool res = false;
        bool to_terminate = false;
        for(char ch: str) {
            const auto &next_it = anext->find(ch);
            if(next_it == anext->end()) {
                to_terminate = true;
                break;
            }
            name = next_it->second;
            const auto &anext_it = a.find(name);
            if(anext_it == a.end()) {
                std::cout << 0 << std::endl << 0 << std::endl << name << std::endl;
                return 1;
            }
            anext = &anext_it->second;
            ++nsteps;
        }
        if(!to_terminate && anext->find(0) != anext->end()) {
            res = true;
        }
        std::cout << res << std::endl;
        std::cout << nsteps << std::endl;
        std::cout << name << std::endl;
    }
    return 0;
}
