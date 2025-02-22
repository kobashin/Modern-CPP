#include <initializer_list>
#include <vector>
#include <iostream>

template <class T>
class Vector {
    std::vector<T> vec_;

    public:
        Vector(std::initializer_list<T> init)
            : vec_(init.begin(), init.end()) {}
        auto begin() const {return vec_.begin();}
        auto end() const {return vec_.end();}
};

int main() {
    const Vector<int> v = {1, 3, 2};

    for (int x : v) {
        std::cout << x << ' ';
    }
    std::cout << std::endl;
}