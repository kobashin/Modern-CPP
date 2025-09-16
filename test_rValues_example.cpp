/*
    https://cpprefjp.github.io/lang/cpp11/rvalue_ref_and_move_semantics.html

    C++11からは、型 T に対して  T&  で宣言される参照型を左辺値参照と呼ぶのに対して、 
    T&&  で宣言される参照型を右辺値参照と呼ぶ。
*/

struct Foo{};
int f() {return 0;}

int main() {
    int i = 0;

    i; // 名前付きオブジェクトは左辺値
    0; // リテラル値は右辺値

    Foo x;

    x; // 名前付きオブジェクトは左辺値
    Foo(); // コンストラクタの戻り値は右辺値

    f(); // 関数の戻り値は右辺値
}
