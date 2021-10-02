#include <cstdlib>

namespace Sample
{
    template<class T, const size_t n, const size_t m>
    class Matrix {
        class Row {
            T row[m];
        public:
            const T& operator[](const size_t j) const {
                return row[j];
            }
            T& operator[](const size_t j) {
                return row[j];
            }
        };
        Row data[n];
    public:
        const Row &operator[](const size_t i) const {
            return data[i];
        }
        Row &operator[](const size_t i) {
            return data[i];
        }
    };
}

//#define _TEST_
#ifdef _TEST_
#include <iostream>
int main()
{
    Sample::Matrix<int, 3, 4> m;

    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 4; ++j) {
            m[i][j] = (i+1) * 10 + j + 1;
            int x = m[i][j];
            std::cout << x << " ";
        }
        std::cout <<std::endl;
    }
}
#endif//__TEST__
