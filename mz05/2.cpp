template <typename Container, typename Functor>
Container myfilter(Container c, Functor pred) {
    Container new_c{};
    for(auto item : c) {
        if(pred(item)) {
            new_c.insert(new_c.end(), item);
        }
    }
    return new_c;
}
