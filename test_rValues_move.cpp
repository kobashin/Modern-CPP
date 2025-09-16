/*
    https://cpprefjp.github.io/lang/cpp11/rvalue_ref_and_move_semantics.html

    C++11からは、型 T に対して  T&  で宣言される参照型を左辺値参照と呼ぶのに対して、 
    T&&  で宣言される参照型を右辺値参照と呼ぶ。
*/
#include <string>
#include <utility>
#include <memory>

int main() {
    /*
        ムーブ
    */
    std::string x = "Hello, world!";
    std::move(x); // Nothing happens.

    // 実際にxからyへ文字列がムーブされる
    std::string y = std::move(x);


    /*
        所有権の移動
    */
    std::unique_ptr<int> p(new int(1));

    // 所有権はqに移り、pはnullptrになる
    std::unique_ptr<int> q = std::move(p);
}