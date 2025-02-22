/*
    https://cpprefjp.github.io/lang/cpp11/rvalue_ref_and_move_semantics.html

    C++11からは、型 T に対して  T&  で宣言される参照型を左辺値参照と呼ぶのに対して、 
    T&&  で宣言される参照型を右辺値参照と呼ぶ。
*/

int main() {
    int x = 0;

    // 左辺値参照
    int& lvalue_ref_1 = x;
    // int& lvalue_ref_1 = 0;   // error : 右辺値を左辺値参照で束縛している

    // 右辺値参照
    // int&& rvalue_ref_1 = x;  // error : 左辺値を右辺値参照で束縛している
    int&& rvalue_ref_1 = 0;

    // const左辺値参照
    const int& const_lvalue_ref_1 = x;
    const int& const_ref_value_1 = 0;   // const左辺値参照は右辺値を束縛できる
}