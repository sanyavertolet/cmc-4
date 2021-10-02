#include <map>
#include <vector>
#include <functional>
#include <string>
namespace numbers {
    complex eval(const std::vector<std::string> &args, const complex &z) {
        complex_stack stack;
        size_t i;
        std::map<char, std::function<void()>> ops = 
        {
            {'(', [&stack, &i, &args]() {
                stack = stack << complex(args[i]);
            }},
            {'z', [&stack, &z]() {
                stack = stack << z;
            }},
            {'+', [&stack]() {
                complex a = +stack;
                stack = ~stack;
                complex b = +stack;
                stack = ~stack;
                stack = stack << (a + b);
            }},
            {'-', [&stack]() {
                complex b = +stack;
                stack = ~stack;
                complex a = +stack;
                stack = ~stack;
                stack = stack << (a - b);
            }},
            {'*', [&stack]() {
                complex b = +stack;
                stack = ~stack;
                complex a = +stack;
                stack = ~stack;
                stack = stack << (a * b);
            }},
            {'/', [&stack]() {
                complex b = +stack;
                stack = ~stack;
                complex a = +stack;
                stack = ~stack;
                stack = stack << (a / b);
            }},
            {'!', [&stack]() {
                complex a = +stack;
                stack = stack << a;
            }},
            {';', [&stack]() {
                stack = ~stack;
            }},
            {'~', [&stack]() {
                complex a = +stack;
                stack = ~stack;
                stack = stack << ~a;
            }},
            {'#', [&stack]() {
                complex a = +stack;
                stack = ~stack;
                stack = stack << -a;
            }}
        };
        for(i = 0; i < args.size(); i++) {
            ops[args[i][0]]();
        }
        return +stack;
    }
}
