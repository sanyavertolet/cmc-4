#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

struct Cell {
    Cell(int p_x = 0, int p_y = 0, int h = 0) : x(p_x), y(p_y), height(h) {}
    int x;
    int y;
    int height;
};
struct cmp {
    bool operator()(Cell c1, Cell c2) const{
        if(c1.height == c2.height) {
            if(c1.y == c2.y) {
                return c1.x < c2.x;
            }
            return c1.y < c2.y;
        }
        return c1.height > c2.height;
    }
};
int get_field(std::vector<std::vector<int>> &field) {
    std::string str;
    int i;
    for(i = 0; std::getline(std::cin, str); i++){
        std::stringstream line(str);
        std::vector<int> row;
        int tmp;
        while(line >> tmp) {
            row.push_back(tmp);
        }
        if(row.size()) {
            field.push_back(row);
        } else {
            break;
        }
    }
    return i;
}
void make_cells(const std::vector<std::vector<int>> &field, std::set<Cell, cmp> &cells) {
    for(unsigned i = 0; i < field.size(); ++i) {
        for(unsigned j = 0; j < field[i].size(); ++j) {
            cells.insert(Cell(j, i, field[i][j]));
        }
    }
}
int get_changes(std::vector<int> &changes) {
    int tmp;
    while(std::cin >> tmp) {
        changes.push_back(tmp);
    }
    return changes.size();
}
bool on_map(const int x, const int y, const std::vector<std::vector<int>> &field) {
    return 0 <= y && unsigned(y) < field.size() && 0 <= x && unsigned(x) < field[y].size();
}
void change(int &height, const int change) {
    if(height > change) {
        height -= change;
    } else {
        height = 0;
    }
}
void accept_change(std::vector<std::vector<int>> &field, std::set<Cell, cmp> &cells, int ch) {
    constexpr int CELLS_AROUND = 8;
    static struct {
        int dy, dx, k;
    } d[CELLS_AROUND] = {
        {-1, 0, 2},
        { 0,+1, 2},
        {+1, 0, 2},
        { 0,-1, 2},
        {-1,-1, 4},
        {+1,-1, 4},
        {-1,+1, 4},
        {+1,+1, 4}
    };
    auto cell = cells.begin();
    int x = cell->x;
    int y = cell->y;
    cells.erase(*cell);
    change(field[y][x], ch);
    cells.insert(Cell(x, y, field[y][x]));
    for(auto d_i : d) {
        int x1 = x + d_i.dx;
        int y1 = y + d_i.dy;
        if(on_map(x1, y1, field)) {
            cells.erase(Cell(x1,y1,field[y1][x1]));
            change(field[y1][x1], ch / d_i.k);
            cells.insert(Cell(x1, y1, field[y1][x1]));
        }
    }
}
void print_field(const std::vector<std::vector<int>> &field) {
    for(auto items : field) {
        for(auto item : items) {
            std::cout << item << " ";
        }
        std::cout << std::endl;
    }
}
int main() {
    std::vector<std::vector<int>> field;
    if(get_field(field)) {
        std::vector<int> changes;
        if(get_changes(changes)) {
            std::set<Cell, cmp> cells;
            make_cells(field, cells);
            std::sort(changes.begin(), changes.end(), std::greater<int>());
            for(auto change : changes) {
                accept_change(field, cells, change);
            }
        }
        print_field(field);
    }
}

