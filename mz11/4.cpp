#include <iostream>
#include <list>
#include <map>
//a+(b*c)           ->      a+b*c
//((a+b)+(c+d))     ->      a+b+(c+d)
//(a+b) + (c+d)

//((a)+b)&c^d       ->      a+b&c^d
//(((a)&b^c|((d)))) ->      a&b^c|d
//a                 ->      a

bool is_op(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '&'
        || ch == '^' || ch == '|';
}

std::list<std::string> parse(std::string &expression) {
    std::list<std::string> expressions;
    for(size_t i = 0; i < expression.size(); ++i) {

    }
    return expressions;
}

int get_priority(char op) {
    static std::map<char, int> op_priority = {
        {'*', 1},
        {'/', 1},
        {'+', 2},
        {'-', 2},
        {'&', 3},
        {'^', 4},
        {'|', 5}
    };
    return op_priority[op];
}

std::string op_analyze() {

}

std::string simplify(std::string &expression, int last_priority) {
    auto expressions = parse(expression);
    return expression;
}

int main() {
    
}
