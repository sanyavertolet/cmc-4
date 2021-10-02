#include <iostream>
#include <map>
#include <utility>
#include <cinttypes>

int main() {
    constexpr uint32_t MODULE = 4294967161;
    std::map<std::pair<uint32_t, uint32_t>, uint32_t> matrix;
    uint32_t row, coloumn, value;
    while(std::cin >> row >> coloumn >> value) {
        if(value != MODULE) {
            auto pos = std::make_pair(row, coloumn);
            matrix[pos] = (uint64_t(matrix[pos]) + uint64_t(value)) % MODULE;
        }
    }
    for(auto &[position, value] : matrix) {
        if(value) {
            std::cout << position.first << " " << position.second
                << " " << value << std::endl;
        }
    }
    return 0;
}
