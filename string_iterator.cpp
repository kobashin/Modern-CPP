#include <string>
#include <iostream>
#include <iterator>

int main() {
    std::string x = "hello";
    std::cout << "x:";
    for (const char& c : x) {
        std::cout << c;
    }
    std::cout << std::endl;

    std::string y(x.rbegin(), x.rend());
    std::cout << "y:" << y << std::endl;
    
    return 0;
}