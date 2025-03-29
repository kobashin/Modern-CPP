#include <iostream>
#include <string>

template <typename... Args>
auto sum(Args... args) {
    return (args + ...);
}

template <typename... Args>
auto sum0(Args... args) {
    return (args + ... + 0);
}

template <typename... Args>
bool all(Args... args) {
    return (... && args);
}

int main() {
    std::cout << sum(1, 2, 4, 8) << std::endl;
    std::cout << sum0(1, 2, 4, 8) << std::endl;
    std::cout << all(true, true, true, true) << std::endl;
    std::cout << all(true, true, false, true) << std::endl;
}