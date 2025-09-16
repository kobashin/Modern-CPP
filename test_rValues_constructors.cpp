/*
    https://cpprefjp.github.io/lang/cpp11/rvalue_ref_and_move_semantics.html

    C++11からは、型 T に対して  T&  で宣言される参照型を左辺値参照と呼ぶのに対して、 
    T&&  で宣言される参照型を右辺値参照と呼ぶ。
*/
#include <algorithm>
#include <iostream>

class large_class {
    private:
        char* ptr;
    public:
        // default constructor
        large_class() {
            ptr = new char[1000];
            // バッファに対して時間のかかる書き込みを実行
            std::cout << "[default constructor]" << std::endl;
        }

        // copy constructor
        // 自クラスへの参照を実引数に持つコンストラクタをコピーコンストラクタという
        large_class(const large_class& r) {
            ptr = new char[1000];
            std::copy(r.ptr, r.ptr + 1000, ptr);
            std::cout << "[copy constructor]" << std::endl;
        }

        // destructor
        ~large_class() {
            delete[] ptr;
            std::cout << "[destructor]" << std::endl;
        }

        // ムーブコンストラクタ
        large_class(large_class&& r) {
            // ポインタの挿げ替え
            ptr = r.ptr;
            // 元のオブジェクトはnullptrに
            r.ptr = nullptr;
            std::cout << "[move constuctor]" << std::endl;
        }

        // ムーブ代入演算子
        large_class& operator=(large_class&& r) {
            // 既存バッファの破棄
            delete[] ptr;
            // ポインタの挿げ替え
            ptr = r.ptr;
            // 元のオブジェクトはnullptrに
            r.ptr = nullptr;
            std::cout << "[move operator=]" << std::endl;
            return *this;
        }
};

int main() {
    /*
        ムーブセマンティクス
    */
    
    /*
    large_class x{};    // [default constructor]
    
    // とても時間がかかる
    large_class y(x);   // [copy constructor]
    */
    
    // 左辺値に対して std::move() を適用すると右辺値となり、ムーブコンストラクタが呼ばれる。
    large_class tmp{};  // [default constructor]
    large_class y{};    // [default constructor]
    large_class z(y);   // [copy constructor]

    large_class x(std::move(tmp)); // tmpをムーブしてxを作る    // [move constuctor]
    y = std::move(x); // xをムーブしてyに代入する   // [move operator=]
    
}