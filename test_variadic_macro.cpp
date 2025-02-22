// https://cpprefjp.github.io/lang/cpp11/variadic_macros.html

#include <cstdio>

#define DEBUG_LOG(fmt, ...) std::printf(fmt, __VA_ARGS__)
#define FORWARD_ARGS(...) __VA_ARGS__

void f1(int a, int b, int c) {
    std::printf("f1 : %d %d %d\n", a, b, c);
}

void f2() {
    std::printf("f2\n");
}

int main() {
    DEBUG_LOG("%s %d\n", "Hello", 42);
    f1(FORWARD_ARGS(1, 2, 3));
    f2(FORWARD_ARGS());
}