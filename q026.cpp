/*
    Input_1 : {'this', 'is', 'an', 'example'}
    Input_2 : {' '}
    Output  : 'this is an example'

    Reference : C++ Pocket Reference P237
*/

#include <iostream>
#include <string>

int main() {
    std::string s;
    char d;

    std::cout << "Enter your String" << std::endl;
    std::getline(std::cin, s);
    
    std::cout << "Enter your delimiter" << std::endl;
    // Cannot receive space as a char...
    std::cin >> d;
    
    std::cout << "String from terminal : " << s << std::endl;
    std::cout << "Delimiter from terminal : " << d << std::endl;
    return 0;
}