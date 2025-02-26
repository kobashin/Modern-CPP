#include <vector>
#include <iostream>

template <class T>
T square(T t) {
    return (t * t);
}

template <class... T>
auto summed_square(T... Args) {
    return (... + square(Args));
}

int main() {
    std::cout << summed_square(3, 4);    // Answer is 25.
}