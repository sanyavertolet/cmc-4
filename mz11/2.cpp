#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <cctype>

int main() {
    std::string left, right;
    std::vector<std::pair<char, std::string>> gramma;
    while(std::cin >> left >> right) {
        gramma.push_back(std::make_pair(left[0], right));
    }
    std::set<char> used;
    std::vector<char> nodes;
    used.insert('S');
    nodes.push_back('S');
    for(size_t i = 0; i < nodes.size(); ++i) {
        for(auto &[name, rule] : gramma) {
            if(nodes[i] == name) {
                for(size_t i = 0; i < rule.size(); ++i) {
                    if(isupper(rule[i])) {
                        if(used.insert(rule[i]).second) {
                            nodes.push_back(rule[i]);
                        }
                    }
                }
            }
        }
    }
    for(auto &[name, rule] : gramma) {
        if(used.find(name) != used.end()) {
            std::cout << name << " " << rule << std::endl;
        }
    }
}
