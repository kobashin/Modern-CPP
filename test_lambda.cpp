#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <algorithm>
#include <cassert>
using namespace std;

void simple_example() {
    
    std::cout << "Test: simple_example()" << std::endl;

    vector<int> v = {1, 2, 3, 4, 5, 6};
    // array<int, 5> a = {3, 4, 6, 8, 9};
    // list<int> l = {0, 2, 5, 6, 9};
    std::cout << "vector<int> v = {1, 2, 3, 4, 5, 6}" << std::endl;

    // auto f = [](int x) {return x > 2;};
    auto f = [](int x)-> bool {return x > 2;};

    /*
        This lambda function defines a function object like this.

        struct F {
            auto operator()(int x) const -> decltype(x > 2) {
                return (x > 2);
            }
        }
    */

    std::cout << "Lambda function: auto f = [](int x)-> bool {return x > 2;}" << std::endl;

    std::cout << "Result of f(v):" << std::endl;
    for (int x : v) {
        cout << f(x) << endl;
    }
}

// https://cpprefjp.github.io/lang/cpp11/lambda_expressions.html
void copy_capture_example() {

    std::cout << "Test: copy_capture_example()" << std::endl;

    int a = 0;
    auto f = [a]() {return a;};
    a = 1;

    // The function uses "a" as of the definition of the function.
    // It means "a" equals 0.
    int result = f();
    std::cout << "a = " << result << std::endl;
}

void reference_capture_example() {

    std::cout << "Test: reference_capture_example()" << std::endl;

    int a = 0;
    auto f = [&a]() {return a;};
    a = 1;

    // A reference-captured variable has value when it's referenced.
    // It means "a" equals 1.
    int result = f();
    std::cout << "a = " << result << std::endl;
}

int main() {

    simple_example();
    copy_capture_example();
    reference_capture_example();

}