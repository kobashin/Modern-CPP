/* 
    任意個数の引数を取ることが出来て、その最小値を返す関数テンプレート
    比較には　operator<演算子を使うこと

    operator<の代わりに引数として与えられた2項比較関数を使う、
    この関数テンプレートの修正版も作成する

    可変引数テンプレート
    https://cpprefjp.github.io/lang/cpp11/variadic_templates.html
*/
#include <iostream>

/*
print関数を例にした可変引数テンプレートの実装

    // 引数が0個になった時に呼び出される関数
void print() {
    std::cout << std::endl;
}

template <typename T, typename ... Types>
// パラメータパックの1つ目とそれ以外の引数、という形で再起処理を実装する
void print(T t1, Types ... tail) {
    std::cout << t1 << ' ';
    print(tail ...);
}

int main() {
    print(1, 2, 3);
    print(1.1, 1.2, 1.23, 12.34, 123.4);
}

C:\Users\shin5\OneDrive\ドキュメント\Modern_C++>q018.exe
1 2 3 
1.1 1.2 1.23 12.34 123.4 

*/

template <typename T>
T min(T t1, T t2) {
    return t1 < t2 ? t1 : t2;
}

template <typename T, typename ... Types>
T min(T t1, Types ... tail) {
    return min(t1, min(tail ...));
}

int main() {
    std::cout << "minimum is ..."
              << min(2, 4, 10, 3, 15, 1)
              << std::endl;

    std::cout << "minimum is ..."
              << min(3.14, 2.78, 2.87, 0.75, 1.5, 1.001)
              << std::endl;
}