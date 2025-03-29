/*
    https://qiita.com/rita0222/items/09e49723e3339ba5de24
*/
#include <stdio.h>

template <typename T>
struct Traits;

template <>
struct Traits<int> {
    static constexpr auto Name = "int";
    static constexpr int Value = 0;
};

template <>
struct Traits<float> {
    static constexpr auto Name = "float";
    static constexpr int Value = 1;
};

template<>
struct Traits<double> {
    static constexpr auto Name = "double";
    static constexpr int Value = 2;
};

int main() {
    printf("i:%s,%d\n", Traits<int>::Name, Traits<int>::Value);
    printf("f:%s,%d\n", Traits<float>::Name, Traits<float>::Value);
    printf("d:%s,%d\n", Traits<double>::Name, Traits<double>::Value);

    return 0;
}