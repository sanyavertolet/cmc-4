#include <iostream>
#include <cinttypes>
#include <algorithm>

unsigned estimate(uint32_t x) {
    int counter = 0;
    for(unsigned i = 0; i < sizeof(x) * 8; ++i, x >>= 1) {
        counter += x & 1;
    }
    return counter;
}

int main() {
    uint64_t w1, w2;
    std::cin >> w1 >> w2;
    uint64_t likes = 0;
    uint64_t dislikes = 0;
    uint32_t bulletin;
    uint64_t votes = 0;
    while(std::cin >> bulletin) {
        likes += estimate(bulletin);
        votes += sizeof(bulletin) * 8;
    }
    dislikes = votes - likes;

    w1 = std::min(dislikes, w1);
    w2 = std::min(likes, w2);

    double worst_case = -1.0 + 2.0 * double(likes - w2) / double(votes);
    double best_case = -1.0 + 2.0 * double(likes + w1) / double(votes);

    std::cout << worst_case << " " << best_case << std::endl;

    return 0;
}
