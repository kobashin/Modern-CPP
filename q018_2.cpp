#include <iostream>
#include <functional>

/*
    2つの引数を持つ方のminimum()を先に定義すべき
    main()で引数2つの関数定義を探そうとすると、ソースコード内で先に定義されているから探す。
    よって、引数2つでもminimum(T1 a, T ... args)の方がヒットしてしまう。
*/
template <typename T>
T minimum(T const a, T const b) {return a < b ? a : b;}

template <typename T1, typename ... T>
T1 minimum(T1 a, T ... args) {
    return minimum(a, minimum(args...));
}

template <class Compare, typename T>
T minimumc(Compare comp, T const a, T const b) {
    return comp(a, b) ? a : b;
}

template <class Compare, typename T1, typename... T>
T1 minimumc(Compare comp, T1 a, T... args) {
    return minimumc(comp, a, minimumc(comp, args...));
}

int main() {
    auto x = minimum(5, 4, 2, 3);
    std::cout << x << std::endl;

    auto y = minimumc(std::less<>(), 3, 2, 9, 4);
    std::cout << y << std::endl;
}