#include <iostream>

int main() {
    int a = 3;
    int b = 5;

    std::cout << "a = " << a << ", b = " << b << std::endl;

    int tmp = a;
    a = b;
    b = tmp;

    std::cout << "a = " << a << ", b = " << b << std::endl;

    return 0;
}