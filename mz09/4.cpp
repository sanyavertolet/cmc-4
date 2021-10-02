#include <iostream>

//#define _TEST_
#ifdef _TEST_

class Holder
{
    int value = 0;

public:
    Holder()
    {
        std::cin >> value;
    }

    ~Holder()
    {
        std::cout << value << std::endl;
    }

    void swap(Holder &other)
    {
        int tmp = value;
        value = other.value;
        other.value = tmp;
    }
};

#endif //_TEST_

#include <iostream>
#include <memory>

int main() {
    int count;
    std::cin >>count;
    Holder* h = new Holder[count]();
    auto ih = &h[0];
    auto ihr = &h[count-1];
    for(; ih < ihr; ++ih, --ihr) {
        ih->swap(*ihr);
    }
    delete[]h;
}

