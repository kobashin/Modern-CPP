/*
    C++ Traits Quiz - Review Modern C++ Template Programming
    
    Instructions:
    1. Fill in the blanks marked with _____ 
    2. Complete the missing code sections
    3. Run the test functions to verify your solutions
    4. Check your answers against the answer section at the bottom
    
    Topics covered:
    - Template specialization
    - Type traits
    - SFINAE (Substitution Failure Is Not An Error)
    - Custom trait implementations
    - STL type_traits usage
*/

#include <iostream>
#include <type_traits>
#include <string>
#include <vector>
#include <cassert>

// ========== SECTION 1: Basic Template Traits ==========

// Fill in the template declaration for a basic traits class
template <typename _____>
struct BasicTraits;

// Specialize BasicTraits for int type
template <>
struct BasicTraits<_____> {
    static constexpr const char* name = "integer";
    static constexpr _____ value = 42;
    using type = _____;
};

// Specialize BasicTraits for float type  
template <>
struct BasicTraits<_____> {
    static constexpr const char* name = "_____";
    static constexpr float value = _____;
    using type = float;
};

// Specialize BasicTraits for std::string
_____ <>
struct BasicTraits<std::string> {
    static constexpr const char* _____ = "string";
    static constexpr int value = 0;
    using _____ = std::string;
};

// ========== SECTION 2: Type Checking Traits ==========

// Create a trait to check if a type is a pointer
template<typename T>
struct is_pointer {
    static constexpr bool _____ = false;
};

// Specialize for pointer types
template<typename T>
struct is_pointer<_____> {
    static constexpr _____ value = true;
};

// Helper variable template (C++14 style)
template<typename T>
constexpr bool is_pointer_v = is_pointer<T>::_____;

// ========== SECTION 3: SFINAE and Enable_if ==========

// Function that only works with integral types
template<typename T>
typename std::_____<std::is_integral<T>::value, T>::type
add_integers(T a, T b) {
    return _____ + _____;
}

// Function that only works with floating point types  
template<typename T>
typename std::enable_if<std::_____<T>::_____, T>::type
add_floats(T a, T b) {
    return a _____ b;
}

// ========== SECTION 4: Container Traits ==========

// Trait to detect if a type has begin() and end() methods
template<typename T, typename = void>
struct is_container : std::_____ {};

template<typename T>
struct is_container<T, std::void_t<
    decltype(std::declval<T>()._____()),
    decltype(std::declval<T>().end())
>> : std::_____ {};

template<typename T>
constexpr bool is_container_v = is_container<T>::_____;

// ========== SECTION 5: Advanced Traits with SFINAE ==========

// Trait to check if a type has a specific member function
template<typename T, typename = void>
struct has_size_method : _____ {};

template<typename T>  
struct has_size_method<T, std::void_t<
    decltype(std::declval<T>()._____)
>> : std::true_type {};

// Function that works only with types that have size() method
template<typename T>
std::enable_if_t<has_size_method<T>::_____, size_t>
get_container_size(const T& container) {
    return container._____();
}

// ========== SECTION 6: Value-based Traits ==========

// Trait to get the number of elements in an array
template<typename T>
struct array_size;

template<typename T, std::size_t N>
struct array_size<T[N]> {
    static constexpr std::size_t _____ = N;
};

// Helper variable template
template<typename T>
constexpr std::size_t array_size_v = array_size<T>::_____;

// ========== SECTION 7: Type Transformation Traits ==========

// Remove const and reference from a type
template<typename T>
struct remove_const_ref {
    using type = typename std::remove_const<
        typename std::_____<T>::type
    >::type;
};

template<typename T>
using remove_const_ref_t = typename remove_const_ref<T>::_____;

// ========== SECTION 8: Inheritance and Concept Traits ==========

// Check if type B is derived from type A
template<typename Base, typename Derived>
struct is_derived_from {
    static constexpr bool _____ = std::is_base_of<_____, Derived>::value;
};

// Helper variable template
template<typename Base, typename Derived>
constexpr bool is_derived_from_v = is_derived_from<_____, _____>::value;

// ========== TEST FUNCTIONS ==========

void test_basic_traits() {
    std::cout << "=== Testing Basic Traits ===" << std::endl;
    
    // Test int specialization
    assert(BasicTraits<int>::value == _____);
    assert(std::string(BasicTraits<int>::name) == "_____");
    
    // Test float specialization  
    assert(BasicTraits<float>::value == 3.14f);
    assert(std::string(BasicTraits<float>::_____) == "floating_point");
    
    // Test string specialization
    assert(BasicTraits<std::string>::_____ == 0);
    assert(std::string(BasicTraits<std::string>::name) == "_____");
    
    std::cout << "Basic traits tests passed!" << std::endl;
}

void test_pointer_traits() {
    std::cout << "=== Testing Pointer Traits ===" << std::endl;
    
    assert(is_pointer_v<int> == _____);
    assert(is_pointer_v<int*> == _____);
    assert(is_pointer_v<const char*> == true);
    assert(is_pointer_v<std::string> == _____);
    
    std::cout << "Pointer traits tests passed!" << std::endl;
}

void test_sfinae_functions() {
    std::cout << "=== Testing SFINAE Functions ===" << std::endl;
    
    // Test integral function
    int result1 = add_integers(5, 10);
    assert(result1 == _____);
    
    // Test floating point function
    double result2 = add_floats(3.5, 2.5);
    assert(result2 == _____);
    
    std::cout << "SFINAE function tests passed!" << std::endl;
}

void test_container_traits() {
    std::cout << "=== Testing Container Traits ===" << std::endl;
    
    assert(is_container_v<std::vector<int>> == _____);
    assert(is_container_v<std::string> == true);
    assert(is_container_v<int> == _____);
    
    std::vector<int> vec = {1, 2, 3, 4, 5};
    assert(get_container_size(vec) == _____);
    
    std::string str = "hello";
    assert(get_container_size(str) == _____);
    
    std::cout << "Container traits tests passed!" << std::endl;
}

void test_array_traits() {
    std::cout << "=== Testing Array Traits ===" << std::endl;
    
    int arr[10];
    double darr[5];
    
    assert(array_size_v<decltype(arr)> == _____);
    assert(array_size_v<decltype(darr)> == _____);
    
    std::cout << "Array traits tests passed!" << std::endl;
}

void test_type_transformation() {
    std::cout << "=== Testing Type Transformation ===" << std::endl;
    
    using original_type = const int&;
    using clean_type = remove_const_ref_t<original_type>;
    
    static_assert(std::is_same_v<clean_type, _____>);
    
    std::cout << "Type transformation tests passed!" << std::endl;
}

void test_inheritance_traits() {
    std::cout << "=== Testing Inheritance Traits ===" << std::endl;
    
    class Base {};
    class Derived : public Base {};
    class Unrelated {};
    
    assert((is_derived_from_v<Base, Derived>) == _____);
    assert((is_derived_from_v<Base, Unrelated>) == _____);
    assert((is_derived_from_v<Derived, Base>) == _____);
    
    std::cout << "Inheritance traits tests passed!" << std::endl;
}

// ========== MAIN FUNCTION ==========
int main() {
    std::cout << "C++ Traits Quiz - Running Tests" << std::endl;
    std::cout << "=================================" << std::endl;
    
    try {
        test_basic_traits();
        test_pointer_traits();
        test_sfinae_functions();
        test_container_traits();
        test_array_traits();
        test_type_transformation();
        test_inheritance_traits();
        
        std::cout << std::endl << "🎉 All tests passed! Great job!" << std::endl;
        std::cout << "You have successfully completed the traits quiz!" << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "❌ Test failed: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}

/*
===============================================================================
                                ANSWER SECTION
===============================================================================

SECTION 1: Basic Template Traits
Line 23: template <typename T>
Line 28: int
Line 30: int
Line 31: int
Line 36: float
Line 37: "floating_point"
Line 38: 3.14f
Line 42: template
Line 44: name
Line 46: type

SECTION 2: Type Checking Traits  
Line 52: value
Line 57: T*
Line 58: bool
Line 63: value

SECTION 3: SFINAE and Enable_if
Line 68: enable_if
Line 70: a + b
Line 75: is_floating_point
Line 75: value
Line 77: +

SECTION 4: Container Traits
Line 82: false_type
Line 87: begin
Line 89: true_type
Line 92: value

SECTION 5: Advanced Traits with SFINAE
Line 97: std::false_type
Line 101: size
Line 106: value
Line 109: size

SECTION 6: Value-based Traits
Line 116: value
Line 120: value

SECTION 7: Type Transformation Traits
Line 126: remove_reference
Line 130: type

TEST FUNCTIONS ANSWERS:
Line 137: 42
Line 138: "integer"  
Line 142: name
Line 145: value
Line 146: "string"
Line 153: false
Line 154: true
Line 156: false
Line 163: 15
Line 167: 6.0
Line 174: true
Line 176: false
Line 179: 5
Line 182: 5
Line 189: 10
Line 190: 5
Line 197: int

SECTION 8: Inheritance and Concept Traits
Line 134: value
Line 135: Base
Line 140: Base
Line 140: Derived

TEST FUNCTIONS ANSWERS:
Line 152: 42
Line 153: "integer"  
Line 157: name
Line 160: value
Line 161: "string"
Line 168: false
Line 169: true
Line 171: false
Line 178: 15
Line 182: 6.0
Line 189: true
Line 191: false
Line 194: 5
Line 197: 5
Line 204: 10
Line 205: 5
Line 212: int
Line 220: true
Line 221: false
Line 222: false

Complete working code can be found in traits_quiz_answers.cpp
*/