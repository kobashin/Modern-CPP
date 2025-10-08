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

    // 注意: endは初期化していないように見えるが、デフォルトコンストラクタが呼ばれる
    // std::sregex_iteratorのデフォルトコンストラクタは終端イテレータを作成する
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

        重要: デフォルトコンストラクタは終端イテレータを作成する
        - std::sregex_iterator end; // 終端イテレータ
        - std::sregex_iterator it(begin, end, regex); // 開始イテレータ

        operator*()	                現在のマッチ結果を取得	std::smatch&
        operator->()	            マッチ結果へのポインタ	std::smatch*
        operator++()	            次のマッチへ進む	sregex_iterator&
        operator==()/operator!=()	イテレータ比較	bool
    */

    // Demo: デフォルトコンストラクタの動作確認
    std::cout << "< Demo: Default constructor behavior >" << std::endl;
    std::sregex_iterator default_iter;  // デフォルトコンストラクタ（終端イテレータ）
    std::sregex_iterator start_iter(std::begin(s), std::end(s), re);  // 開始イテレータ
    
    // 最初は異なる
    std::cout << "start_iter == default_iter: " << (start_iter == default_iter) << std::endl;
    
    // すべてのマッチを進めると同じになる
    while (start_iter != default_iter) {
        ++start_iter;
    }
    std::cout << "After iterating, start_iter == default_iter: " << (start_iter == default_iter) << std::endl;

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

    // Test: regex_search (from q067.cpp password validation)
    std::cout << "< Test: regex_search for password validation >" << std::endl;
    std::vector<std::string> passwords = {
        "1234-5678",     // has symbol
        "password123",   // no symbol
        "Pass@word1",    // has symbol
        "simple"         // no symbol
    };
    
    // Regex for symbols: !#$%&-=@;:_
    std::regex symbol_re("[!#$%&\\-=@;:_]");
    
    for (const auto& pwd : passwords) {
        bool hasSymbol = std::regex_search(pwd, symbol_re);
        std::cout << "Password: '" << pwd << "' -> Symbol check: " 
                  << (hasSymbol ? "OK" : "NG") << std::endl;
    }
    
    /*
        std::regex_search() searches for the first match in the string
        Returns true if a match is found, false otherwise
        Used in q067.cpp for password validation to check if special symbols exist
        
        Difference from std::sregex_iterator:
        - regex_search: finds if pattern exists (returns bool)
        - sregex_iterator: iterates through all matches (returns iterator)
    */

}