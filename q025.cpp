/*
    capitalize
    "the c++ challenger"
    "The C++ Challenger"

    reference
    https://cpprefjp.github.io/reference/string/basic_string/find.html
*/

#include <iostream>
#include <string>
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

    std::string s1 = "the c++ challenger";
    int pos = s1.find(' ');
    std::cout << "position of ' ' : " << pos << std::endl;
    // assert(isupper(s1[0]) > 0);
    return 0;
}