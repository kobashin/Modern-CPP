// https://cpprefjp.github.io/lang/cpp17/folding_expressions.html

#include <vector>
#include <string>
#include <iostream>

template <typename... Args>
auto sum(Args... args) {
    return (args + ...);
}

template <typename... Args>
auto sum_with_fallback(Args... args) {
    return (args + ... + 0);
}

template <typename... Args>
bool all(Args... args) {
    // 短絡評価をうまく使うには、左畳み込みの方が効率が良い？
    return (... && args);
    /// return (args && ...);
}

template <typename... Args>
void print_all(std::ostream& os, Args... args) {
    (os << ... << args);
}

template <class T>
T square(T t) {
    return (t * t);
}

template <class... T>
auto summed_square(T... Args) {
    return (... + square(Args));
    // return (... + (Args * Args));    // OK
}

int main() {
    std::cout << "-auto sum(Args... args)-" << std::endl;
    sum(1, 2, 3, 4);
    
    std::cout << "-auto sum_with_fallback(Args... args)-" << std::endl;
    sum();
    
    std::cout << "-bool all(Args... args)-" << std::endl;
    all(true, true, true);
    
    std::cout << "-void print_all(std::ostream& os, Args... args)-" << std::endl;
    print_all(std::cout, 1, 2, 3, '\n');

    std::cout << "-summed_square(3, 4)-" << std::endl;
    std::cout << summed_square(3, 4);    // Answer is 25.
}
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