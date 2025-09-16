/*
    Lambda Quiz - Modern C++ Lambda Expressions
    
    This quiz covers various aspects of lambda expressions in C++.
    Fill in the blanks to complete the working code.
    
    Topics covered:
    - Basic lambda syntax
    - Capture mechanisms (by value, by reference, mixed)
    - Return types
    - Mutable lambdas
    - Generic lambdas
    - Lambdas with algorithms
    - Nested lambdas
    - Lambda with containers
    
    Instructions:
    1. Fill in all the blanks marked with ______ 
    2. Some blanks may require multiple words or symbols
    3. Pay attention to capture syntax and return types
    4. After completing, compile and run to test your answers
    5. Check results against expected output in comments
*/

#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <cassert>
#include <numeric>
#include <string>

using namespace std;

int main() {
    cout << "=== Lambda Quiz - Fill in the blanks ===" << endl;
    
    // ========== SECTION 1: Basic Lambda Syntax ==========
    cout << "\n--- Section 1: Basic Lambda Syntax ---" << endl;
    
    vector<int> v = {1, 2, 3, 4, 5, 6};
    array<int, 5> a = {3, 4, 6, 8, 9};
    list<int> l = {0, 2, 5, 6, 9};

    // 1. Create a lambda that returns true if x > 2
    auto f1 = ________(int x)______ ______ {return x > 2;};
    
    cout << "Testing f1(3): " << f1(3) << " (expected: 1)" << endl;
    cout << "Testing f1(1): " << f1(1) << " (expected: 0)" << endl;

    // 2. Create a lambda that doubles its input
    auto double_func = ________(int n) { return n __ 2; };
    
    cout << "Testing double_func(5): " << double_func(5) << " (expected: 10)" << endl;

    // ========== SECTION 2: Capture by Value ==========
    cout << "\n--- Section 2: Capture by Value ---" << endl;
    
    int multiplier = 3;
    
    // 3. Create a lambda that captures 'multiplier' by value and multiplies input by it
    auto multiply_by_captured = ________multiplier________(int x) {
        return x * ________;
    };
    
    cout << "multiply_by_captured(4): " << multiply_by_captured(4) << " (expected: 12)" << endl;
    
    // Change multiplier - captured value should not change
    multiplier = 10;
    cout << "After changing multiplier to 10, multiply_by_captured(4): " << multiply_by_captured(4) << " (expected: 12)" << endl;

    // ========== SECTION 3: Capture by Reference ==========
    cout << "\n--- Section 3: Capture by Reference ---" << endl;
    
    int counter = 0;
    
    // 4. Create a lambda that captures 'counter' by reference and increments it
    auto increment_counter = ________counter________() {
        return ________counter;
    };
    
    cout << "Initial counter: " << counter << " (expected: 0)" << endl;
    cout << "increment_counter(): " << increment_counter() << " (expected: 1)" << endl;
    cout << "Counter after increment: " << counter << " (expected: 1)" << endl;

    // ========== SECTION 4: Mixed Capture ==========
    cout << "\n--- Section 4: Mixed Capture ---" << endl;
    
    int base = 10;
    int factor = 2;
    
    // 5. Create a lambda that captures 'base' by value and 'factor' by reference
    auto mixed_capture = ________base, ________factor________(int x) {
        factor = 5; // This should change the original factor
        return (x + ________) * factor;
    };
    
    cout << "mixed_capture(3): " << mixed_capture(3) << " (expected: 65)" << endl;
    cout << "Factor after lambda call: " << factor << " (expected: 5)" << endl;

    // ========== SECTION 5: Mutable Lambda ==========
    cout << "\n--- Section 5: Mutable Lambda ---" << endl;
    
    int captured_value = 7;
    
    // 6. Create a mutable lambda that captures by value and modifies the captured value
    auto mutable_lambda = ________captured_value________ ________ () {
        captured_value += 3;
        return captured_value;
    };
    
    cout << "mutable_lambda(): " << mutable_lambda() << " (expected: 10)" << endl;
    cout << "mutable_lambda(): " << mutable_lambda() << " (expected: 13)" << endl;
    cout << "Original captured_value: " << captured_value << " (expected: 7)" << endl;

    // ========== SECTION 6: Auto Return Type ==========
    cout << "\n--- Section 6: Auto Return Type ---" << endl;
    
    // 7. Create a lambda with explicit return type (double)
    auto flexible_return = ________(bool return_int) ______ ______ {
        if (return_int) {
            return ________; // return double 42.0
        } else {
            return ________; // return double 3.14
        }
    };
    
    cout << "flexible_return(true): " << flexible_return(true) << " (expected: 42)" << endl;
    cout << "flexible_return(false): " << flexible_return(false) << " (expected: 3.14)" << endl;

    // ========== SECTION 7: Generic Lambda ==========
    cout << "\n--- Section 7: Generic Lambda ---" << endl;
    
    // 8. Create a generic lambda that works with any type
    auto generic_add = ________(________ a, ________ b) {
        return a + b;
    };
    
    cout << "generic_add(5, 3): " << generic_add(5, 3) << " (expected: 8)" << endl;
    cout << "generic_add(2.5, 1.5): " << generic_add(2.5, 1.5) << " (expected: 4)" << endl;
    cout << "generic_add(string(\"Hello\"), string(\" World\")): " << generic_add(string("Hello"), string(" World")) << " (expected: Hello World)" << endl;

    // ========== SECTION 8: Lambda with Algorithms ==========
    cout << "\n--- Section 8: Lambda with Algorithms ---" << endl;
    
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> evens;
    
    // 9. Use copy_if with a lambda to copy even numbers
    ________(numbers.begin(), numbers.end(), ________(evens), 
             ________(int n) { return n __ 2 == 0; });
    
    cout << "Even numbers: ";
    for (int n : evens) {
        cout << n << " ";
    }
    cout << " (expected: 2 4 6 8 10)" << endl;

    // 10. Use transform with a lambda to square all numbers
    vector<int> squares(numbers.size());
    ________(numbers.begin(), numbers.end(), squares.begin(),
             ________(int n) { return n __ n; });
    
    cout << "First 5 squares: ";
    for (int i = 0; i < 5; ++i) {
        cout << squares[i] << " ";
    }
    cout << " (expected: 1 4 9 16 25)" << endl;

    // ========== SECTION 9: Lambda with find_if ==========
    cout << "\n--- Section 9: Lambda with find_if ---" << endl;
    
    vector<string> words = {"apple", "banana", "cherry", "date", "elderberry"};
    
    // 11. Find first word longer than 5 characters
    auto it = ________(words.begin(), words.end(), 
                      ________(const string& word) {
                          return word.________ > 5;
                      });
    
    if (it != words.end()) {
        cout << "First word longer than 5 chars: " << *it << " (expected: banana)" << endl;
    }

    // ========== SECTION 10: Lambda with Accumulate ==========
    cout << "\n--- Section 10: Lambda with Accumulate ---" << endl;
    
    vector<int> values = {1, 2, 3, 4, 5};
    
    // 12. Use accumulate with lambda to find product of all values
    int product = ________(values.begin(), values.end(), ________, 
                          ________(int a, int b) { return a __ b; });
    
    cout << "Product of 1,2,3,4,5: " << product << " (expected: 120)" << endl;

    // ========== SECTION 11: Nested Lambda ==========
    cout << "\n--- Section 11: Nested Lambda ---" << endl;
    
    // 13. Create a lambda that returns another lambda
    auto create_adder = ________(int increment) {
        return ________increment________(int value) {
            return value + ________;
        };
    };
    
    auto add_five = create_adder(5);
    cout << "add_five(10): " << add_five(10) << " (expected: 15)" << endl;

    // ========== SECTION 12: Lambda with Capture All ==========
    cout << "\n--- Section 12: Lambda with Capture All ---" << endl;
    
    int x = 10, y = 20, z = 30;
    
    // 14. Create lambda that captures all variables by value
    auto capture_all_val = ________() {
        return x + y + z;
    };
    
    cout << "capture_all_val(): " << capture_all_val() << " (expected: 60)" << endl;
    
    // 15. Create lambda that captures all variables by reference  
    auto capture_all_ref = ________() {
        x += 1; y += 1; z += 1;
        return x + y + z;
    };
    
    cout << "capture_all_ref(): " << capture_all_ref() << " (expected: 63)" << endl;
    cout << "x, y, z after ref capture: " << x << ", " << y << ", " << z << " (expected: 11, 21, 31)" << endl;

    // ========== SECTION 13: Lambda Function Objects ==========
    cout << "\n--- Section 13: Lambda Function Objects ---" << endl;
    
    // 16. Store lambda in std::function
    ________ <________(int, int)> calculator = ________(int a, int b) {
        return a * b + 10;
    };
    
    cout << "calculator(3, 4): " << calculator(3, 4) << " (expected: 22)" << endl;

    // ========== SECTION 14: Recursive Lambda ==========
    cout << "\n--- Section 14: Recursive Lambda ---" << endl;
    
    // 17. Create a recursive lambda for factorial (using std::function)
    ________ <________(int)> factorial = ________(int n) {
        return (n <= 1) ? 1 : n * ________(n - 1);
    };
    
    cout << "factorial(5): " << factorial(5) << " (expected: 120)" << endl;

    // ========== SECTION 15: Complex Lambda Expression ==========
    cout << "\n--- Section 15: Complex Lambda Expression ---" << endl;
    
    vector<pair<string, int>> people = {{"Alice", 25}, {"Bob", 30}, {"Charlie", 20}, {"Diana", 35}};
    
    // 18. Sort people by age using lambda
    ________(people.begin(), people.end(),
            ________(const pair<string, int>& a, const pair<string, int>& b) {
                return a.________ < b.________;
            });
    
    cout << "People sorted by age: ";
    for (const auto& person : people) {
        cout << person.first << "(" << person.second << ") ";
    }
    cout << " (expected: Charlie(20) Alice(25) Bob(30) Diana(35))" << endl;

    // ========== SECTION 16: Lambda with Custom Comparator ==========
    cout << "\n--- Section 16: Lambda with Custom Comparator ---" << endl;
    
    vector<int> nums = {5, 2, 8, 1, 9, 3};
    
    // 19. Sort in descending order using lambda comparator
    ________(nums.begin(), nums.end(), ________(int a, int b) {
        return a __ b; // greater than comparison
    });
    
    cout << "Descending order: ";
    for (int n : nums) {
        cout << n << " ";
    }
    cout << " (expected: 9 8 5 3 2 1)" << endl;

    // ========== TEST FUNCTIONS ==========
    cout << "\n=== Running Test Functions ===" << endl;
    
    // Test assertions - these should all pass if quiz is completed correctly
    assert(f1(3) == true);
    assert(f1(1) == false);
    assert(double_func(5) == 10);
    assert(increment_counter() == 2); // counter was already incremented once
    assert(counter == 2);
    assert(factor == 5);
    assert(generic_add(5, 3) == 8);
    assert(evens.size() == 5);
    assert(squares[0] == 1 && squares[1] == 4);
    assert(product == 120);
    assert(add_five(10) == 15);
    assert(x == 11 && y == 21 && z == 31);
    assert(calculator(3, 4) == 22);
    assert(factorial(5) == 120);
    assert(nums[0] == 9 && nums[1] == 8); // Check descending sort
    
    cout << "All tests passed! Quiz completed successfully!" << endl;
    
    return 0;
}

/*
    Answer Key:
    
    1. [](int x)-> bool
    2. [] , *
    3. [=] , multiplier
    4. [&counter] , ++counter
    5. [=, &factor] , base
    6. [=] , mutable
    7. [] , -> , double , 42.0 , 3.14
    8. [] , auto , auto
    9. copy_if , back_inserter , [] , %
    10. transform , [] , *
    11. find_if , [] , length()
    12. accumulate , 1 , [] , *
    13. [] , [=] , increment
    14. [=] 
    15. [&]
    16. std::function , int , []
    17. std::function , int , [&factorial] , factorial
    18. sort , [] , second , second
    19. sort , [] , >
*/