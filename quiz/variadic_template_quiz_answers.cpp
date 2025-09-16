/*
    Variadic Template Quiz - ANSWERS
    
    This file contains the complete solution to the variadic template quiz.
    Use this to check your answers or as a reference.
    
    Compilation: g++ -std=c++17 variadic_template_quiz_answers.cpp -o quiz_answers && ./quiz_answers
*/

#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <list>
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <utility>
#include <type_traits>

// ===== SECTION 1: Basic Variadic Template Function =====

// Base case: when parameter pack is empty
void print() {
    // Do nothing - base case for recursion
}

// Recursive case: handle one parameter and recurse with the rest
template <class Head, class ... Tail>
void print(Head&& head, Tail&& ... tail) {
    std::cout << head << std::endl;
    print(tail...);
}

// ===== SECTION 2: Folding Expressions =====

// Sum function using folding expression
template <typename ... Args>
auto sum(Args ... args) {
    return (args + ...);
}

// Sum with fallback value (handles empty parameter pack)
template <typename... Args>
auto sum_with_fallback(Args... args) {
    return (args + ... + 0);
}

// Logical AND for all arguments
template <typename... Args>
bool all(Args... args) {
    return (... && args);
}

// Print all arguments to output stream
template <typename... Args>
void print_all(std::ostream& os, Args... args) {
    (os << ... << args);
}

// Square function helper
template <class T>
T square(T t) {
    return (t * t);
}

// Sum of squares using folding expression
template <class... T>
auto summed_square(T... Args) {
    return (... + square(Args));
}

// ===== SECTION 3: Container Operations with Variadic Templates =====

// Generic push_back function for containers
template <typename C, typename ... Args>
void push_back(C& c, Args&& ... args) {
    // Use folding expression to call push_back for each argument
    (c.push_back(args), ...);
}

// ===== SECTION 4: Advanced Pattern - contains_any/all/none =====

template <typename Container>
bool contains(Container c, int a) {
    auto found = std::find(c.cbegin(), c.cend(), a);
    return (found != c.cend());
}

// contains_any - base case
bool contains_any(std::vector<int> v, int a) {
    return contains(v, a);
}

// contains_any - recursive case
template <typename ... Types>
bool contains_any(std::vector<int> v, int t1, Types ... args) {
    bool tmp_tf = contains(v, t1);
    return tmp_tf || contains_any(v, args...);
}

// contains_all - base case
bool contains_all(std::array<int, 6> a, int x) {
    return contains(a, x);
}

// contains_all - recursive case
template <typename... Types>
bool contains_all(std::array<int, 6> a, int t1, Types... args) {
    bool tmp_tf = contains(a, t1);
    return tmp_tf && contains_all(a, args...);
}

// ===== SECTION 5: Perfect Forwarding =====

// Function that perfectly forwards arguments to another function
template <typename Func, typename ... Args>
auto call_function(Func&& func, Args&& ... args) -> decltype(func(std::forward<Args>(args)...)) {
    return std::forward<Func>(func)(std::forward<Args>(args)...);
}

// Test function for perfect forwarding
void test_func(int& x, const std::string& s) {
    x += 10;
    std::cout << "Modified x: " << x << ", String: " << s << std::endl;
}

// ===== SECTION 6: Variadic Macros =====

#define DEBUG_LOG(fmt, ...) std::printf(fmt, __VA_ARGS__)
#define FORWARD_ARGS(...) __VA_ARGS__

void f1(int a, int b, int c) {
    std::printf("f1 : %d %d %d\n", a, b, c);
}

void f2() {
    std::printf("f2\n");
}

// ===== SECTION 7: Type Traits with Variadic Templates =====

// Check if all types are the same
template <typename ... T>
struct all_same : std::true_type {};

template <typename T, typename U, typename... Rest>
struct all_same<T, U, Rest...> : std::bool_constant<
    std::is_same_v<T, U> && all_same<U, Rest...>::value> {};

// Helper variable template
template <typename... Types>
constexpr bool all_same_v = all_same<Types...>::value;

// ===== SECTION 8: Variadic Class Template =====

// A tuple-like class template
template <typename ... Types>
class simple_tuple;

// Specialization for empty tuple
template <>
class simple_tuple<> {};

// Recursive specialization
template <typename Head, typename ... Tail>
class simple_tuple<Head, Tail...> : private simple_tuple<Tail...> {
private:
    Head head_value;
    
public:
    simple_tuple(Head head, Tail ... tail) 
        : simple_tuple<Tail...>(std::forward<Tail>(tail)...), 
          head_value(std::forward<Head>(head)) {}
    
    Head& get_head() { return head_value; }
    const Head& get_head() const { return head_value; }
    const simple_tuple<Tail...>& get_tail() const { 
        return static_cast<const simple_tuple<Tail...>&>(*this); 
    }
};

// ===== TEST FUNCTIONS =====

void test_basic_print() {
    std::cout << "\n=== Testing Basic Print Function ===" << std::endl;
    print(1, 'a', "hello", 3.14);
}

void test_folding_expressions() {
    std::cout << "\n=== Testing Folding Expressions ===" << std::endl;
    
    std::cout << "sum(1, 2, 3, 4) = " << sum(1, 2, 3, 4) << std::endl;
    std::cout << "sum_with_fallback() = " << sum_with_fallback() << std::endl;
    std::cout << "all(true, true, true) = " << all(true, true, true) << std::endl;
    std::cout << "all(true, false, true) = " << all(true, false, true) << std::endl;
    
    std::cout << "print_all: ";
    print_all(std::cout, 1, 2, 3, '\n');
    
    std::cout << "summed_square(3, 4) = " << summed_square(3, 4) << std::endl;
}

void test_container_operations() {
    std::cout << "\n=== Testing Container Operations ===" << std::endl;
    
    std::vector<int> v;
    push_back(v, 1, 2, 3, 4, 5);
    
    std::cout << "Vector contents: ";
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}

void test_contains_functions() {
    std::cout << "\n=== Testing Contains Functions ===" << std::endl;
    
    std::vector<int> v{1, 2, 3, 4, 5, 6};
    std::array<int, 6> a{{1, 2, 3, 4, 5, 6}};
    
    assert(contains_any(v, 0, 6, 7));
    std::cout << "contains_any test passed" << std::endl;
    
    assert(contains_all(a, 2, 5, 6));
    std::cout << "contains_all test passed" << std::endl;
}

void test_perfect_forwarding() {
    std::cout << "\n=== Testing Perfect Forwarding ===" << std::endl;
    
    int x = 5;
    std::string s = "test";
    call_function(test_func, x, s);
    std::cout << "Final x value: " << x << std::endl;
}

void test_variadic_macros() {
    std::cout << "\n=== Testing Variadic Macros ===" << std::endl;
    
    DEBUG_LOG("%s %d\n", "Hello", 42);
    f1(FORWARD_ARGS(1, 2, 3));
    f2(FORWARD_ARGS());
}

void test_type_traits() {
    std::cout << "\n=== Testing Type Traits ===" << std::endl;
    
    static_assert(all_same_v<int, int, int>);
    static_assert(!all_same_v<int, double, int>);
    std::cout << "Type traits tests passed" << std::endl;
}

void test_tuple_class() {
    std::cout << "\n=== Testing Simple Tuple ===" << std::endl;
    
    simple_tuple<int, std::string, double> t(42, "hello", 3.14);
    std::cout << "Tuple head: " << t.get_head() << std::endl;
}

int main() {
    std::cout << "Variadic Template Quiz - Running Tests" << std::endl;
    std::cout << "If all tests pass, your answers are correct!" << std::endl;
    
    try {
        test_basic_print();
        test_folding_expressions();
        test_container_operations();
        test_contains_functions();
        test_perfect_forwarding();
        test_variadic_macros();
        test_type_traits();
        test_tuple_class();
        
        std::cout << "\n🎉 All tests passed! Great job!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "\n❌ Test failed: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}