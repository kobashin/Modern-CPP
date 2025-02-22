// https://cpprefjp.github.io/lang/cpp11/variadic_templates.html

#include <iostream>
#include <utility>

// パラメータパックが空になったら終了
void print() {}

/*
    一つ以上のパラメータを受け取るようにし、
    可変引数の先頭とそれ以外に分割する
*/
template <class Head, class ... Tail>
void print(Head&& head, Tail&& ... tail) {
    std::cout << head << std::endl;
    print(tail ...);
}

int main() {
    print(1, 'a', "hello");
}