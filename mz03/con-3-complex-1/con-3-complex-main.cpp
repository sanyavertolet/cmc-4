#include <map>
#include <vector>
#include <functional>

#include "complex.h"

int
main(int argc, char *argv[])
{
    if(1) {
        numbers::complex a(1, 2);
        numbers::complex b("(2,3)");

        a.print("a=");
        b.print("b=");
        (a+b).print("a+b=");
        (a-b).print("a-b=");
        ((a+b)/2).print("(a*b)/2=");
        (a*b).print("a*b=");
        (a/b).print("a/b=");
    }

    if(1) {
        std::cout <<std::endl;
        numbers::complex a(1, 1);
        numbers::complex b(2, 2);
        numbers::complex c(3, 3);

        numbers::complex_stack stack1;

        stack1 = stack1 << a;
        stack1 = stack1; // @suppress("Assignment to itself")
        stack1.print("stack1: ");

        numbers::complex_stack stack2;
        stack2 = stack1 <<b <<c;
        stack2.print("stack2 = stack1 <<b <<c: ");
        stack2 = ~stack2;
        stack2.print("stack2 = ~stack2: ");

        numbers::complex_stack stack3 = stack1 <<b <<c;
        stack3.print("stack3 = stack1 <<b <<c: ");

        stack3 = stack3 << +stack3;
        stack3.print("stack3 = stack3 << +stack3: ");

        +stack3 = -+stack3;
        stack3.print("+stack3 = -+stack3: ");

        +stack3 = ~+stack3;
        stack3.print("+stack3 = ~+stack3: ");

        stack3 = ~~stack3;
        stack3.print("stack3 = ~~stack3: ");
    }

    if(1) {
        std::cout <<std::endl;
        numbers::complex z("(1,2)");
        z.print("z=");
        numbers::complex a = numbers::eval({"z", "z", "~", "+"}, z);
        a.print("z z ~ +:");
        a = numbers::eval({"z", "~"}, z);
        a.print("z~:");
        a = numbers::eval({"(1,2)", "(1,-2)", "+"}, z);
        a.print("(1,2)+(1,-2):");
    }

    if(1) {
        std::cout <<std::endl;
        // "(25,50)" "10" "100" "(1,0)" "z" "/"
        numbers::complex c_2(2.0);
        numbers::complex c(argv[1]);
        double r = std::stod(argv[2]);
        int n = std::stoi(argv[3]);
        std::vector<std::string> function(argv + 4, argv + argc);
        double seg = 2.0 * M_PI / n;
        numbers::complex result;
        numbers::complex vec_prev(1, 0);
        for(int i = 1; i <= n; i++) {
            double phi = seg * i;
            numbers::complex vec(std::cos(phi), std::sin(phi));
            numbers::complex r_c(r, 0);
            result += numbers::eval(function, c + r_c * r_c * (vec + vec_prev)/c_2) * (vec - vec_prev);
            vec_prev = vec;
        }
        std::cout << result.to_string() << std::endl;
    }
    return 0;
}

