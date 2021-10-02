#include <iostream>
#include <algorithm>

template<typename T>
class Coord {
public:
    Coord(T r = T(), T c = T()) : row(r), col(c) {}
    typedef T value_type;
    T row;
    T col;
};

template<typename T>
auto dist(Coord<T> &size, Coord<T> &p1, Coord<T> &p2) {
    auto r_min = std::min(p1.row, p2.row);
    auto r_max = std::max(p1.row, p2.row);

    auto c_min = std::min(p1.col, p2.col);
    auto c_max = std::max(p1.col, p2.col);
    
    auto delta_r = std::min(r_max - r_min, r_min + size.row - r_max);
    auto delta_c = std::min(c_max - c_min, c_min + size.row - c_max);
    
    return std::max(delta_r, delta_c);
}

//#define _TEST_
#ifdef _TEST_
int main() {
    Coord<long> p1(1, 0);
    Coord<long> p2(4, 4);
    Coord<long> size(5, 5);
    std::cout << dist(size, p1, p2) << std::endl;

    return 0;
}
#endif
