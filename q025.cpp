/*
    capitalize
    "the c++ challenger"
    "The C++ Challenger"

    reference
    https://cpprefjp.github.io/reference/string/basic_string/find.html
*/

#include <iostream>
#include <string>
#include <cctype>
#include <cassert>

/*
bool is_capital(std::string const & str, int pos) {
    // check if str[pos] is capital
}
*/

int main() {
    char c = 'c';
    // char* c1 = 'abc';   // error
    // char[] c2 = 'abc';   // error
    // char c2[] = 'abc';   // error
    // char c3[3] = 'abc';   // error
    char c3[3] = {'a', 'b', 'c'};

    char upper = std::toupper(c);   // Convert to uppercase
    std::cout << "Upper case : " << upper << std::endl;

    std::string s1 = "the c++ challenger";
    int pos = -1;
    std::cout << "position of ' ' : " << pos << std::endl;
    // assert(isupper(s1[0]) > 0);

    // test : toupper()
    // s1[0] = std::toupper(s1[0]);
    // std::cout << "s1 : " << s1 << std::endl;
    
    do {
        s1[pos + 1] = std::toupper(s1[pos + 1]);
        pos = s1.find(' ', pos + 1);
    } while (!(pos == std::string::npos));

    std::cout << "s1 : " << s1 << std::endl;
    
    return 0;
}