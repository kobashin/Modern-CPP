/*
    Variadic Template Quiz - Modern C++ Review
    
    Instructions:
    1. Fill in the blanks marked with _______ or /* BLANK */
    2. Some lines are completely missing - add them where indicated
    3. Compile and run the test functions to verify your answers
    4. Refer to the answer section at the bottom if needed
    
    Topics covered:
    - Basic variadic template syntax
    - Parameter pack expansion
    - Recursive template instantiation
    - Folding expressions (C++17)
    - Perfect forwarding with variadic templates
    - Variadic macros
    
    Compilation: g++ -std=c++17 variadic_template_quiz.cpp -o quiz && ./quiz
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
// Based on test_variadic_template.cpp

// Base case: when parameter pack is empty
void print() {
    /* BLANK - complete this function */
}

// Recursive case: handle one parameter and recurse with the rest
_______ <_______ Head, _______ ... Tail>
void print(_______ head, _______ ... tail) {
    std::cout << _______ << std::endl;
    _______(_______);
}

// ===== SECTION 2: Folding Expressions =====
// Based on test_folding_expression.cpp

// Sum function using folding expression
template <_______ ... Args>
auto sum(_______ ... args) {
    return (_______ + _______);
}

// Sum with fallback value (handles empty parameter pack)
template <typename... Args>
auto sum_with_fallback(Args... args) {
    return (_______ + ... + _______);
}

// Logical AND for all arguments
template <typename... Args>
_______ all(Args... args) {
    return (_______ && _______);
}

// Print all arguments to output stream
template <typename... Args>
void print_all(std::ostream& os, Args... args) {
    (_______ << ... << _______);
}

// Square function helper
template <class T>
T square(T t) {
    return (_______);
}

// Sum of squares using folding expression
_______ <class... T>
auto summed_square(T... Args) {
    return (... + _______(_______));
}

// ===== SECTION 3: Container Operations with Variadic Templates =====
// Based on q020.cpp style

// Generic push_back function for containers
template <_______ C, _______ ... Args>
void push_back(_______ c, _______ ... args) {
    // Use folding expression to call push_back for each argument
    (_______._______(_______), ...);
}

// ===== SECTION 4: Advanced Pattern - contains_any/all/none =====
// Based on q020.cpp

template <typename Container>
bool contains(Container c, int a) {
    auto found = std::find(c.cbegin(), c.cend(), a);
    return (_______ != _______);
}

// contains_any - base case
bool contains_any(std::vector<int> v, int a) {
    return _______(_______);
}

// contains_any - recursive case
_______ <_______ ... Types>
bool contains_any(std::vector<int> v, int t1, _______ ... args) {
    bool tmp_tf = contains(v, t1);
    return _______ || _______(_______);
}

// contains_all - base case
bool contains_all(std::array<int, 6> a, int x) {
    return /* BLANK */;
}

// contains_all - recursive case
template <typename... Types>
bool contains_all(_______ a, int t1, Types... args) {
    _______ tmp_tf = contains(a, t1);
    return tmp_tf _______ contains_all(_______);
}

// ===== SECTION 5: Perfect Forwarding =====

// Function that perfectly forwards arguments to another function
template <_______ Func, _______ ... Args>
auto call_function(_______ func, _______ ... args) -> decltype(func(_______)) {
    return func(_______(_______));
}

// Test function for perfect forwarding
void test_func(int& x, const std::string& s) {
    x += 10;
    std::cout << "Modified x: " << x << ", String: " << s << std::endl;
}

// ===== SECTION 6: Variadic Macros =====
// Based on test_variadic_macro.cpp

#define DEBUG_LOG(fmt, _______) std::printf(_______, _______)
#define FORWARD_ARGS(_______) _______

void f1(int a, int b, int c) {
    std::printf("f1 : %d %d %d\n", a, b, c);
}

void f2() {
    std::printf("f2\n");
}

// ===== SECTION 7: Type Traits with Variadic Templates =====

// Check if all types are the same
template <_______ T>
struct all_same : std::true_type {};

template <typename T, typename U, typename... Rest>
struct all_same<T, U, Rest...> : std::bool_constant<
    std::is_same_v<_______, _______> && all_same<_______, _______>::value> {};

// Helper variable template
template <typename... Types>
constexpr bool all_same_v = _______<_______>::_______;

// ===== SECTION 8: Variadic Class Template =====

// A tuple-like class template
template <_______ ... Types>
class simple_tuple;

// Specialization for empty tuple
template <>
class simple_tuple<> {};

// Recursive specialization
template <_______ Head, _______ ... Tail>
class simple_tuple<_______, _______> : private simple_tuple<_______> {
private:
    _______ head_value;
    
public:
    simple_tuple(_______ head, _______ ... tail) 
        : simple_tuple<Tail...>(std::forward<Tail>(tail)...), 
          head_value(_______(_______)) {}
    
    _______ get_head() const { return head_value; }
    const simple_tuple<_______>& get_tail() const { 
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

/*
============================================================================
                            ANSWER SECTION
============================================================================

SECTION 1: Basic Variadic Template Function
- void print() { }  // Base case does nothing
- template <class Head, class ... Tail>
- void print(Head&& head, Tail&& ... tail)
- head
- print(tail...)

SECTION 2: Folding Expressions  
- template <typename ... Args>
- Args ... args
- args + ...
- args + ... + 0
- bool
- ... && args
- os << ... << args
- t * t
- template
- square(Args)

SECTION 3: Container Operations
- typename C, typename ... Args
- C& c, Args&& ... args
- c.push_back(args)

SECTION 4: Contains Functions
- found != c.cend()
- contains(v, a)
- template <typename ... Types>
- Types ... args  
- tmp_tf || contains_any(v, args...)
- contains(a, x)
- std::array<int, 6> a
- bool
- && contains_all(a, args...)

SECTION 5: Perfect Forwarding
- typename Func, typename ... Args
- Func&& func, Args&& ... args
- std::forward<Args>(args)...
- std::forward<Func>(func)

SECTION 6: Variadic Macros
- __VA_ARGS__
- fmt, __VA_ARGS__
- ...
- __VA_ARGS__

SECTION 7: Type Traits
- typename ... Types
- std::is_same_v<T, U> && all_same<U, Rest...>::value
- U, Rest...
- all_same_v<Types...>
- all_same<Types...>::value

SECTION 8: Variadic Class Template
- typename ... Types
- typename Head, typename ... Tail
- Head, Tail...
- Tail...
- Head head
- Tail ... tail
- std::forward<Head>(head)
- Head&
- Tail...

============================================================================
*/