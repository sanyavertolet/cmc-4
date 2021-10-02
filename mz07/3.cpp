#include <string>
#include <utility>
#include <sstream>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <functional>

class Factory {
private:
    Factory() {}
    ~Factory() {}

    Factory(Factory &other) = delete;
    Factory(const Factory &other) = delete;
    Factory(Factory &&other) = delete;
    Factory& operator=(Factory &other) = delete;
    Factory& operator=(const Factory &other) = delete;
    Factory& operator=(Factory &&other) = delete;

    static std::map<char, std::function<Figure* (std::string)>> figure_make_;
    static Factory *instance_;

public:
    static Factory* factory_instance() {
        if(instance_ == nullptr) {
            instance_ = new Factory;

        }
        return instance_;
    }
    void factory_instance_release() {
        if(instance_) {
            delete instance_;
            instance_ = nullptr;
        }
    }
    void add(char type, std::string &str, std::vector<Figure*> &v) {
        v.push_back(figure_make_[type](str));
    }
};
std::map<char, std::function<Figure* (std::string)>> Factory::figure_make_
{
    {'R', Rectangle::make},
    {'S', Square::make},
    {'C', Circle::make}
};
Factory *Factory::instance_ = nullptr;

int main() {
    std::vector<Figure*> v;
    auto f = Factory::factory_instance();

    for(char type; std::cin >> type; ) {
        std::string str;
        getline(std::cin, str);
        f->add(type, str, v);
    }

    auto cmp = [](const Figure *a, const Figure *b){
        return a->get_square() < b->get_square();
    };
    std::stable_sort(v.begin(), v.end(), cmp);

    for(auto fig: v) {
        std::cout << fig->to_string() << std::endl;
    }
    for(auto fig: v) {
        delete fig;
    }
    f->factory_instance_release();
    return 0;
}
