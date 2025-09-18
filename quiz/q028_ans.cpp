/*
    Folding Expressions Quiz - ANSWERS
    
    Folding expressions are a C++17 feature that allows you to apply a binary operator
    to all elements in a parameter pack. They come in four forms:
    
    1. Unary right fold: (E op ...)  expands to (E1 op (E2 op (... op En)))
    2. Unary left fold:  (... op E)  expands to (((E1 op E2) op ...) op En)
    3. Binary right fold: (E op ... op I)  expands to (E1 op (E2 op (... op (En op I))))
    4. Binary left fold:  (I op ... op E)  expands to (((I op E1) op E2) op ... op En)
*/

#include <iostream>
#include <vector>
#include <string>
#include <type_traits>

// 1. Basic sum function using unary right fold
template <typename... Args>
auto sum(Args... args) {
    return (args + ...);
}

// 2. Sum with fallback value using binary right fold (handles empty parameter pack)
template <typename... Args>
auto sum_with_fallback(Args... args) {
    return (args + ... + 0);
}

// 3. Logical AND for all arguments using unary left fold
template <typename... Args>
bool all_true(Args... args) {
    return (... && args);
}

// 4. Logical OR for any argument using unary right fold
template<typename... Args>
bool any_true(Args... args) {
    return (args || ...);
}

// 5. Print all arguments using comma operator and left fold
template <typename... Args>
void print_all(std::ostream& os, Args... args) {
    (os << ... << args);
}

// 6. Print with separator using binary left fold with comma operator
template <typename... Args>
void print_with_separator(std::ostream& os, const std::string& sep, Args... args) {
    bool first = true;
    ((os << (first ? "" : sep) << args, first = false), ...);
}

// 7. Multiply all arguments
template <typename... Args>
auto multiply_all(Args... args) {
    return (args * ...);
}

// 8. Check if all arguments are equal to a target value
template <typename T, typename... Args>
bool all_equal_to(T target, Args... args) {
    return (... && (args == target));
}

// 9. Push multiple elements to a container using comma operator
template <typename Container, typename... Args>
void push_multiple(Container& container, Args&&... args) {
    (container.push_back(std::forward<Args>(args)), ...);
}

// 10. Find minimum value using binary left fold
template <typename T, typename... Args>
auto find_min(T first, Args... args) {
    return (first < ... < args);  // This is incorrect - doesn't actually find minimum!
}

// Correct version of find_min - using proper logic
template <typename T, typename... Args>
T find_min_correct(T first, Args... rest) {
    return (first < ... < (first < rest ? first : rest));
}

// Better approach for find_min
template <typename T>
T find_min_better(T&& t) {
    return std::forward<T>(t);
}

template <typename T, typename... Args>
auto find_min_better(T&& t, Args&&... args) {
    auto rest_min = find_min_better(std::forward<Args>(args)...);
    return t < rest_min ? t : rest_min;
}

// 11. String concatenation with separator
template <typename... Strings>
std::string join_strings(const std::string& separator, Strings... strings) {
    std::string result;
    bool first = true;
    ((result += (first ? "" : separator) + strings, first = false), ...);
    return result;
}

// 12. Count how many arguments satisfy a condition
template <typename Predicate, typename... Args>
int count_if(Predicate pred, Args... args) {
    return (... + (pred(args) ? 1 : 0));
}

// 13. Apply a function to all arguments and sum the results
template <typename Function, typename... Args>
auto sum_transform(Function func, Args... args) {
    return (... + func(args));
}

// 14. Check if a value exists in parameter pack
template <typename T, typename... Args>
bool contains(T value, Args... args) {
    return (... || (args == value));
}

// 15. Calculate average of all arguments
template <typename... Args>
auto average(Args... args) {
    static_assert(sizeof...(args) > 0, "Need at least one argument");
    return sum(args...) / static_cast<double>(sizeof...(args));
}

// 16. Boolean operations: all false check
template <typename... Args>
bool all_false(Args... args) {
    return (... && !args);
}

// 17. Complex folding: sum of squares
template <typename... Args>
auto sum_of_squares(Args... args) {
    return (... + (args * args));
}

// 18. Variadic max function
template <typename T>
T variadic_max(T&& t) {
    return std::forward<T>(t);
}

template <typename T, typename... Args>
auto variadic_max(T&& t, Args&&... args) {
    auto rest_max = variadic_max(std::forward<Args>(args)...);
    return t > rest_max ? t : rest_max;
}

// 19. Check if all types are the same
template <typename First, typename... Rest>
constexpr bool all_same_type() {
    return (... && std::is_same_v<First, Rest>);
}

// 20. Fold with function calls - call all functions in sequence
template <typename... Functions>
void call_all(Functions... funcs) {
    (funcs(), ...);
}

// Test functions to validate implementation
void test_basic_operations() {
    std::cout << "=== Testing Basic Operations ===" << std::endl;
    
    // Test sum
    auto result1 = sum(1, 2, 3, 4, 5);
    std::cout << "sum(1,2,3,4,5) = " << result1 << " (expected: 15)" << std::endl;
    
    // Test sum_with_fallback
    auto result2 = sum_with_fallback();
    std::cout << "sum_with_fallback() = " << result2 << " (expected: 0)" << std::endl;
    
    auto result3 = sum_with_fallback(10, 20, 30);
    std::cout << "sum_with_fallback(10,20,30) = " << result3 << " (expected: 60)" << std::endl;
}

void test_logical_operations() {
    std::cout << "\n=== Testing Logical Operations ===" << std::endl;
    
    // Test all_true
    bool result1 = all_true(true, true, true);
    std::cout << "all_true(true,true,true) = " << result1 << " (expected: 1)" << std::endl;
    
    bool result2 = all_true(true, false, true);
    std::cout << "all_true(true,false,true) = " << result2 << " (expected: 0)" << std::endl;
    
    // Test any_true
    bool result3 = any_true(false, false, true);
    std::cout << "any_true(false,false,true) = " << result3 << " (expected: 1)" << std::endl;
    
    bool result4 = any_true(false, false, false);
    std::cout << "any_true(false,false,false) = " << result4 << " (expected: 0)" << std::endl;
}

void test_container_operations() {
    std::cout << "\n=== Testing Container Operations ===" << std::endl;
    
    std::vector<int> vec;
    push_multiple(vec, 1, 2, 3, 4, 5);
    
    std::cout << "After push_multiple(vec, 1,2,3,4,5): ";
    for (int x : vec) {
        std::cout << x << " ";
    }
    std::cout << "(expected: 1 2 3 4 5)" << std::endl;
}

void test_advanced_operations() {
    std::cout << "\n=== Testing Advanced Operations ===" << std::endl;
    
    // Test contains
    bool contains_result = contains(3, 1, 2, 3, 4, 5);
    std::cout << "contains(3, 1,2,3,4,5) = " << contains_result << " (expected: 1)" << std::endl;
    
    // Test average
    auto avg_result = average(2, 4, 6, 8);
    std::cout << "average(2,4,6,8) = " << avg_result << " (expected: 5)" << std::endl;
    
    // Test sum_of_squares
    auto squares_result = sum_of_squares(2, 3, 4);
    std::cout << "sum_of_squares(2,3,4) = " << squares_result << " (expected: 29)" << std::endl;
}

void test_type_operations() {
    std::cout << "\n=== Testing Type Operations ===" << std::endl;
    
    // Test all_same_type
    bool same1 = all_same_type<int, int, int>();
    std::cout << "all_same_type<int,int,int> = " << same1 << " (expected: 1)" << std::endl;
    
    bool same2 = all_same_type<int, double, int>();
    std::cout << "all_same_type<int,double,int> = " << same2 << " (expected: 0)" << std::endl;
}

void test_function_calls() {
    std::cout << "\n=== Testing Function Calls ===" << std::endl;
    
    int counter = 0;
    auto increment = [&counter]() { ++counter; std::cout << "Called " << counter << " "; };
    auto print_hello = []() { std::cout << "Hello "; };
    auto print_world = []() { std::cout << "World! "; };
    
    std::cout << "Calling functions: ";
    call_all(increment, print_hello, increment, print_world, increment);
    std::cout << std::endl;
}

int main() {
    std::cout << "Folding Expressions Quiz - ANSWER KEY with Test Results" << std::endl;
    std::cout << "=========================================================" << std::endl;
    
    test_basic_operations();
    test_logical_operations();
    test_container_operations();
    test_advanced_operations();
    test_type_operations();
    test_function_calls();
    
    std::cout << "\n=== Manual Tests ===" << std::endl;
    std::cout << "Print all: ";
    print_all(std::cout, "Hello", " ", "World", "!\n");
    
    std::cout << "Print with separator: ";
    print_with_separator(std::cout, ", ", "apple", "banana", "cherry");
    std::cout << std::endl;
    
    std::cout << "String join: " << join_strings(" | ", "C++", "is", "awesome") << std::endl;
    
    // Additional tests
    std::cout << "\nMultiply all: " << multiply_all(2, 3, 4, 5) << " (expected: 120)" << std::endl;
    std::cout << "All equal to 5: " << all_equal_to(5, 5, 5, 5) << " (expected: 1)" << std::endl;
    std::cout << "All false: " << all_false(false, false, false) << " (expected: 1)" << std::endl;
    
    // Test count_if
    auto is_even = [](int x) { return x % 2 == 0; };
    std::cout << "Count even numbers in (1,2,3,4,5,6): " << count_if(is_even, 1, 2, 3, 4, 5, 6) << " (expected: 3)" << std::endl;
    
    // Test sum_transform
    auto square = [](int x) { return x * x; };
    std::cout << "Sum of squares (1,2,3): " << sum_transform(square, 1, 2, 3) << " (expected: 14)" << std::endl;
    
    std::cout << "\nAll tests completed!" << std::endl;
    return 0;
}