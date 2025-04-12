/*
    Input_1 : {'this', 'is', 'an', 'example'}
    Input_2 : {' '}
    Output  : 'this is an example'

    Reference : C++ Pocket Reference P237
*/

#include <iostream>
#include <string>

void joinString(std::initializer_list<std::string> list, char c) {
    /* 
    for (std::string str : list) {
        std::cout << str << c;
    }
    std::cout << std::endl; 
    */
    auto itr_begin = list.begin();
    auto itr_end = list.end();

    while ((itr_begin + 1) != itr_end) {
        std::cout << *itr_begin << c;
        ++itr_begin;
    }
    std::cout << *itr_begin << std::endl;
}

int main() {
    /*
    std::string s;
    char d;

    std::cout << "Enter your String" << std::endl;
    std::getline(std::cin, s);
    
    std::cout << "Enter your delimiter" << std::endl;
    */
    
    // Cannot receive white space as a char...
    // std::cin >> d;

    /*
        By using manipulator std::noskipws,
        white space also will become a target of std::cin.

        https://cpprefjp.github.io/reference/ios/noskipws.html
    */
    
    /*
    std::cin >> std::noskipws >> d;

    
    std::cout << "String from terminal : " << s << std::endl;
    std::cout << "Delimiter from terminal : '" << d  << "'" << std::endl;
    */
    
    joinString({"Pen", "pineapple", "apple", "pen."}, ' ');
    
    return 0;
}