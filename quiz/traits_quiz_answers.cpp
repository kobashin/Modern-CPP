/*
    C++ Traits Quiz - Complete Answer Key
    
    This file contains the complete working solutions for the traits quiz.
    Study this code to understand the concepts and verify your answers.
*/

#include <iostream>
#include <type_traits>
#include <string>
#include <vector>
#include <cassert>

// ========== SECTION 1: Basic Template Traits ==========

template <typename T>
struct BasicTraits;

template <>
struct BasicTraits<int> {
    static constexpr const char* name = "integer";
    static constexpr int value = 42;
    using type = int;
};

template <>
struct BasicTraits<float> {
    static constexpr const char* name = "floating_point";
    static constexpr float value = 3.14f;
    using type = float;
};

template <>
struct BasicTraits<std::string> {
    static constexpr const char* name = "string";
    static constexpr int value = 0;
    using type = std::string;
};

// ========== SECTION 2: Type Checking Traits ==========

template<typename T>
struct is_pointer {
    static constexpr bool value = false;
};

template<typename T>
struct is_pointer<T*> {
    static constexpr bool value = true;
};

template<typename T>
constexpr bool is_pointer_v = is_pointer<T>::value;

// ========== SECTION 3: SFINAE and Enable_if ==========

template<typename T>
typename std::enable_if<std::is_integral<T>::value, T>::type
add_integers(T a, T b) {
    return a + b;
}

template<typename T>
typename std::enable_if<std::is_floating_point<T>::value, T>::type
add_floats(T a, T b) {
    return a + b;
}

// ========== SECTION 4: Container Traits ==========

template<typename T, typename = void>
struct is_container : std::false_type {};

template<typename T>
struct is_container<T, std::void_t<
    decltype(std::declval<T>().begin()),
    decltype(std::declval<T>().end())
>> : std::true_type {};

template<typename T>
constexpr bool is_container_v = is_container<T>::value;

// ========== SECTION 5: Advanced Traits with SFINAE ==========

template<typename T, typename = void>
struct has_size_method : std::false_type {};

template<typename T>  
struct has_size_method<T, std::void_t<
    decltype(std::declval<T>().size())
>> : std::true_type {};

template<typename T>
std::enable_if_t<has_size_method<T>::value, size_t>
get_container_size(const T& container) {
    return container.size();
}

// ========== SECTION 6: Value-based Traits ==========

template<typename T>
struct array_size;

template<typename T, std::size_t N>
struct array_size<T[N]> {
    static constexpr std::size_t value = N;
};

template<typename T>
constexpr std::size_t array_size_v = array_size<T>::value;

// ========== SECTION 7: Type Transformation Traits ==========

template<typename T>
struct remove_const_ref {
    using type = typename std::remove_const<
        typename std::remove_reference<T>::type
    >::type;
};

template<typename T>
using remove_const_ref_t = typename remove_const_ref<T>::type;

// ========== SECTION 8: Inheritance and Concept Traits ==========

template<typename Base, typename Derived>
struct is_derived_from {
    static constexpr bool value = std::is_base_of<Base, Derived>::value;
};

template<typename Base, typename Derived>
constexpr bool is_derived_from_v = is_derived_from<Base, Derived>::value;

// ========== TEST FUNCTIONS ==========

void test_basic_traits() {
    std::cout << "=== Testing Basic Traits ===" << std::endl;
    
    assert(BasicTraits<int>::value == 42);
    assert(std::string(BasicTraits<int>::name) == "integer");
    
    assert(BasicTraits<float>::value == 3.14f);
    assert(std::string(BasicTraits<float>::name) == "floating_point");
    
    assert(BasicTraits<std::string>::value == 0);
    assert(std::string(BasicTraits<std::string>::name) == "string");
    
    std::cout << "Basic traits tests passed!" << std::endl;
}

void test_pointer_traits() {
    std::cout << "=== Testing Pointer Traits ===" << std::endl;
    
    assert(is_pointer_v<int> == false);
    assert(is_pointer_v<int*> == true);
    assert(is_pointer_v<const char*> == true);
    assert(is_pointer_v<std::string> == false);
    
    std::cout << "Pointer traits tests passed!" << std::endl;
}

void test_sfinae_functions() {
    std::cout << "=== Testing SFINAE Functions ===" << std::endl;
    
    int result1 = add_integers(5, 10);
    assert(result1 == 15);
    
    double result2 = add_floats(3.5, 2.5);
    assert(result2 == 6.0);
    
    std::cout << "SFINAE function tests passed!" << std::endl;
}

void test_container_traits() {
    std::cout << "=== Testing Container Traits ===" << std::endl;
    
    assert(is_container_v<std::vector<int>> == true);
    assert(is_container_v<std::string> == true);
    assert(is_container_v<int> == false);
    
    std::vector<int> vec = {1, 2, 3, 4, 5};
    assert(get_container_size(vec) == 5);
    
    std::string str = "hello";
    assert(get_container_size(str) == 5);
    
    std::cout << "Container traits tests passed!" << std::endl;
}

void test_array_traits() {
    std::cout << "=== Testing Array Traits ===" << std::endl;
    
    int arr[10];
    double darr[5];
    
    assert(array_size_v<decltype(arr)> == 10);
    assert(array_size_v<decltype(darr)> == 5);
    
    std::cout << "Array traits tests passed!" << std::endl;
}

void test_type_transformation() {
    std::cout << "=== Testing Type Transformation ===" << std::endl;
    
    using original_type = const int&;
    using clean_type = remove_const_ref_t<original_type>;
    
    static_assert(std::is_same_v<clean_type, int>);
    
    std::cout << "Type transformation tests passed!" << std::endl;
}

void test_inheritance_traits() {
    std::cout << "=== Testing Inheritance Traits ===" << std::endl;
    
    class Base {};
    class Derived : public Base {};
    class Unrelated {};
    
    assert((is_derived_from_v<Base, Derived>) == true);
    assert((is_derived_from_v<Base, Unrelated>) == false);
    assert((is_derived_from_v<Derived, Base>) == false);
    
    std::cout << "Inheritance traits tests passed!" << std::endl;
}

// ========== MAIN FUNCTION ==========
int main() {
    std::cout << "C++ Traits Quiz - Answer Key Verification" << std::endl;
    std::cout << "==========================================" << std::endl;
    
    try {
        test_basic_traits();
        test_pointer_traits();
        test_sfinae_functions();
        test_container_traits();
        test_array_traits();
        test_type_transformation();
        test_inheritance_traits();
        
        std::cout << std::endl << "🎉 All answer key tests passed!" << std::endl;
        std::cout << "The complete solutions are working correctly!" << std::endl;
        
        // Additional demonstrations
        std::cout << std::endl << "=== Additional Demonstrations ===" << std::endl;
        
        std::cout << "BasicTraits<int>::name = " << BasicTraits<int>::name << std::endl;
        std::cout << "BasicTraits<float>::value = " << BasicTraits<float>::value << std::endl;
        std::cout << "is_pointer_v<double*> = " << std::boolalpha << is_pointer_v<double*> << std::endl;
        std::cout << "is_container_v<std::vector<int>> = " << is_container_v<std::vector<int>> << std::endl;
        
        std::cout << std::endl << "Study these implementations to master C++ traits!" << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "❌ Test failed: " << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}

/*
===============================================================================
                          EXPLANATION OF KEY CONCEPTS
===============================================================================

1. TEMPLATE SPECIALIZATION:
   - Primary template defines the general structure
   - Specializations provide specific implementations for particular types
   - Can partially or fully specialize templates

2. TYPE TRAITS:
   - Classes that provide information about types at compile time
   - Usually contain static constexpr members or type aliases
   - Foundation for template metaprogramming

3. SFINAE (Substitution Failure Is Not An Error):
   - Allows templates to be removed from overload resolution if substitution fails
   - Used with std::enable_if to conditionally enable/disable templates
   - Essential for creating type-safe generic code

4. VOID_T IDIOM:
   - std::void_t maps any sequence of types to void
   - Used to detect if expressions are valid at compile time
   - Modern way to implement detection idioms

5. VARIABLE TEMPLATES:
   - C++14 feature for creating templated variables
   - _v suffix is standard library convention for convenience aliases
   - Simplifies syntax for accessing trait values

6. TYPE TRANSFORMATION:
   - Traits that modify types (add/remove const, reference, etc.)
   - Usually provide a 'type' member typedef
   - _t suffix is convention for type alias templates

This quiz covers fundamental concepts needed for modern C++ template programming!
*/