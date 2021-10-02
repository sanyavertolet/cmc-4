#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double num;
    double sum = 0;
    double sqrsum = 0;
    int n = 0;
    while(std::cin >> num) {
        sum += num;
        sqrsum += num * num;
        n++;
    }
    double avg = sum / n;
    std::cout << std::setprecision(10) << avg << ' ';
    std::cout << std::setprecision(10) << sqrt(sqrsum / n - avg * avg) << std::endl;
}
