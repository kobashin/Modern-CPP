// C++ Pocket Rerefence P235
#include <string>
#include <iostream>
#include <istream>
#include <sstream>  // This is not mentioned in the book.

int main() {
    // skipws
    std::string s = " A  Z";
    std::cout << "skipws:" << std::endl;
    std::istringstream s1{s};
    char cs[2];
    s1 >> cs[0] >> cs[1];
    for (char c : cs) {
        std::cout << '"' << c << '"' << std::endl;
        /*
            "A"
            "Z"
        */
    }

    // noskipws
    std::cout << "noskipws:" << std::endl;
    std::istringstream s2{s};
    char cns[5];
    s2 >> std::noskipws >> cns[0] >> cns[1] >> cns[2] >> cns[3] >> cns[4];
    for (char c : cns) {
        std::cout << '"' << c << '"' << std::endl;
    }
    return 0;
}