// https://cpprefjp.github.io/reference/regex/regex_iterator.html

#include <iostream>
#include <iterator>
#include <regex>
#include <string>
#include <vector>

template <class Iterator, class T>
Iterator my_find(Iterator first, Iterator last, T value) {
    while (first != last) {

        // Iterator can refer values indirectory by '*'. 
        if (*first == value) {
            return first;
        }

        // Iterator can move to next value by '++'.
        ++first;
    }
    return first;
}

int main() {
    // Test: sregex_iterator()
    std::cout << "< Test: sregex_iterator >" << std::endl;
    std::string s("a01da123456da999d");
    std::regex re("\\d+");

    for (std::sregex_iterator it(std::begin(s), std::end(s), re), end; it != end; ++it) {
        auto&& m = *it;
        std::cout << "position = " << m.position() 
                  << ", length = " << m.length() 
                  << ", str = '" << m.str() 
                  << '\'' << std::endl;
    }

    /*
        std::sregex_iteratorは
        std::basic_regex_iterator<std::string::const_iterator>の別名

        operator*()	                現在のマッチ結果を取得	std::smatch&
        operator->()	            マッチ結果へのポインタ	std::smatch*
        operator++()	            次のマッチへ進む	sregex_iterator&
        operator==()/operator!=()	イテレータ比較	bool
    */

    // Test: my iterator
    std::cout << "< Test: iterator >" << std::endl;
    std::vector<int> v = {1, 2, 3, 4, 5};
    decltype(v)::iterator it = my_find(v.begin(), v.end(), 3);

    if (it != v.end()) {
        std::cout << *it << std::endl;
    }
    else {
        // found nothing
    }

    // Test: next()
    std::cout << "< Test: next() >" << std::endl;
    it = my_find(v.begin(), next(v.begin(), 3), 2);
    std::cout << "my_find(v.begin(), next(v.begin(), 3), 2) = " << *it << std::endl;

    // Test: using pointer as an iterator
    std::cout << "< Test: using pointer as an iterator >" << std::endl;
    int ar[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int* p = my_find(ar, ar + 10, 7);
    if (p != ar + 10) {
        std::cout << "*p = " << *p << std::endl;
    }

}