#include <iostream>
#include <algorithm>

namespace Game {
    template<typename T>
    class Coord {
    public:
        Coord(T r = T(), T c = T()) : row(r), col(c) {}
        using value_type = T;
        T row;
        T col;
    };

    template<typename T>
    auto dist(Game::Coord<T> &size, Game::Coord<T> &p1, Game::Coord<T> &p2) {
        auto delta_r = std::max(p1.row, p2.row) - std::min(p1.row, p2.row);
        auto delta_c = std::max(p1.col, p2.col) - std::min(p1.col, p2.col);

        int extra_step;
        if((!(p1.col % 2) && (p1.row > p2.row)) || ((p1.col % 2) && (p1.row < p2.row))) {
            extra_step = 1;
        } else {
            extra_step = 0;
        }
        auto x = (delta_c + !extra_step) / 2;
        if(delta_r < x) {
            x = 0;
            delta_r = 0;
        }

        return delta_c + delta_r - x;
    }
}
//#define _TEST_
#ifdef _TEST_
int main() {
    Game::Coord<long> p1;
    Game::Coord<long> p2;
    Game::Coord<long> size;
    while(std::cin >> size.row >> size.col >> p1.row >> p1.col >> p2.row >> p2.col) {
        std::cout << Game::dist(size, p1, p2) << std::endl;
    }
    return 0;
}
#endif
