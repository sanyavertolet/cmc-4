#include <functional>
#include <iterator>
#include <algorithm>
#include <vector>

template<typename It_i, typename It>
It myremove(const It_i begin, const It_i end, It first, It last) {
    std::vector<typename std::iterator_traits<It_i>::value_type> to_delete(begin, end);
    std::sort(to_delete.begin(), to_delete.end());
    auto del_it_last = std::unique(to_delete.begin(), to_delete.end());
    auto del_it = to_delete.begin();
    int n = std::distance(first, last);
    int deleted = 0;
    int i0 = 0;
    int i1 = *del_it;
    It it = first;
    for(; del_it != del_it_last && i1 < n - deleted; ++del_it) {
        i1 = *del_it - deleted;
        if(i1 >= i0) {
            int step = i1 - i0;
            std::advance(it, step);
            It to = it;
            It from = std::next(to);
            ++deleted;
            int to_delete = n - deleted - i1;
            for(int i = 0; i < to_delete; ++i, ++to, ++from) {
                *to = std::move(*from);
            }
            i0 = i1;
        }
    }
    return std::next(it, n - deleted - i0);
}
