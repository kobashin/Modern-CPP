// https://cpprefjp.github.io/reference/memory/shared_ptr.html
#include <iostream>
#include <memory>

struct X {
    X () {
        std::cout << "X ctor called." << std::endl;
    }

    ~X () {
       std::cout << "~X dtor called." << std::endl;
    }
};

struct Y {
    Y () {
        std::cout << "Y ctor called." << std::endl;
    }

    ~Y () {
        std::cout << "~Y dtor called." << std::endl;
    }
};

int main () {
    std::shared_ptr<void> p(new X());

    p.reset(new Y());

    return 0;
}
