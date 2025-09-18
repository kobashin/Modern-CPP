/*
    rValue Quiz - ANSWER VERSION 
    This is the complete working version to verify the quiz functions properly
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <memory>

// ============================================================================
// SECTION 1: Basic rValue Concepts
// ============================================================================

struct Foo{};
int f() {return 0;}

void test_basic_rvalue_concepts() {
    std::cout << "\n=== Testing Basic rValue Concepts ===" << std::endl;
    
    int i = 0;

    // Fill in the blanks: What type of value are these?
    i;      // Named objects are lvalue values (lvalue/rvalue)
    0;      // Literal values are rvalue values (lvalue/rvalue) 

    Foo x;
    x;      // Named objects are lvalue values (lvalue/rvalue)
    Foo();  // Constructor return values are rvalue values (lvalue/rvalue)

    f();    // Function return values are rvalue values (lvalue/rvalue)
    
    std::cout << "Basic rValue concepts test completed." << std::endl;
}

// ============================================================================
// SECTION 2: Reference Types and Binding Constraints  
// ============================================================================

void test_reference_binding() {
    std::cout << "\n=== Testing Reference Binding ===" << std::endl;
    
    int x = 0;

    // Fill in the reference types:
    int& lvalue_ref_1 = x;          // lvalue reference type
    // int& lvalue_ref_error = 0;                  // Error: cannot bind rvalue to lvalue reference
    
    // int&& rvalue_ref_error = x;     // Error: cannot bind lvalue to rvalue reference  
    int&& rvalue_ref_1 = 0;        // rvalue reference type

    // const lvalue reference - special case
    const int& const_lvalue_ref_1 = x;    // can bind lvalue
    const int& const_lvalue_ref_2 = 0;    // can also bind rvalue (lvalue/rvalue)
    
    std::cout << "Reference binding test completed." << std::endl;
}

// ============================================================================
// SECTION 3: Move Constructor and Move Semantics
// ============================================================================

class large_class {
    private:
        char* ptr;
    public:
        // Default constructor
        large_class() {
            ptr = new char[1000];
            std::cout << "[default constructor]" << std::endl;  // Fill in constructor type
        }

        // Copy constructor - takes const reference to same class
        large_class(const large_class& r) {
            ptr = new char[1000];
            std::copy(r.ptr, r.ptr + 1000, ptr);
            std::cout << "[copy constructor]" << std::endl;  // Fill in constructor type
        }

        // Destructor
        ~large_class() {
            delete[] ptr;
            std::cout << "[destructor]" << std::endl;  // Fill in what this is
        }

        // Move constructor - takes rvalue reference
        large_class(large_class&& r) {
            // Transfer ownership - fill in the implementation
            ptr = r.ptr;        // Transfer pointer
            r.ptr = nullptr;      // Set original to safe state
            std::cout << "[move constructor]" << std::endl;  // Fill in constructor type
        }

        // Move assignment operator
        large_class& operator=(large_class&& r) {
            // Clean up existing resource
            delete[] ptr;
            
            // Transfer ownership - fill in the implementation  
            ptr = r.ptr;        // Transfer pointer
            r.ptr = nullptr;      // Set original to safe state
            std::cout << "[move operator=]" << std::endl;  // Fill in operator type
            
            return *this;
        }
        
        // Helper method to check if object is valid
        bool is_valid() const {
            return ptr != nullptr;
        }
};

void test_move_semantics() {
    std::cout << "\n=== Testing Move Semantics ===" << std::endl;
    
    // This will call default constructor
    large_class tmp{};
    
    // This will call default constructor  
    large_class y{};
    
    // This will call copy constructor (copy/move)
    large_class z(y);

    // Using std::move to force move constructor
    // Fill in the function that converts lvalue to rvalue:
    large_class x(std::move(tmp));
    
    // Using std::move for move assignment
    // Fill in the function call:
    y = std::move(x);
    
    // Test validity after moves
    std::cout << "tmp valid after move: " << (tmp.is_valid() ? "true" : "false") << std::endl;
    std::cout << "x valid after move: " << (x.is_valid() ? "true" : "false") << std::endl;
    std::cout << "y valid after move assignment: " << (y.is_valid() ? "true" : "false") << std::endl;
}

// ============================================================================  
// SECTION 4: std::move and Ownership Transfer
// ============================================================================

void test_string_move() {
    std::cout << "\n=== Testing String Move ===" << std::endl;
    
    std::string x = "Hello, world!";
    
    // This line doesn't actually move anything - fill in what happens:
    std::move(x); // Function name - Nothing happens because result is not assigned
    
    // This actually moves the string - fill in the function:
    std::string y = std::move(x);
    
    std::cout << "x after move: '" << x << "'" << std::endl;
    std::cout << "y after move: '" << y << "'" << std::endl;
}

void test_unique_ptr_ownership() {
    std::cout << "\n=== Testing Unique Pointer Ownership Transfer ===" << std::endl;
    
    // Create unique_ptr - fill in template parameter type:
    std::unique_ptr<int> p(new int(1));
    
    std::cout << "p points to: " << (p ? "valid object" : "nullptr") << std::endl;
    std::cout << "Value: " << (p ? *p : 0) << std::endl;
    
    // Transfer ownership - fill in the function call:
    std::unique_ptr<int> q = std::move(p);
    
    std::cout << "After ownership transfer:" << std::endl;
    std::cout << "p points to: " << (p ? "valid object" : "nullptr") << std::endl;  
    std::cout << "q points to: " << (q ? "valid object" : "nullptr") << std::endl;
    std::cout << "Value in q: " << (q ? *q : 0) << std::endl;
}

// ============================================================================
// SECTION 5: Advanced Move Scenarios
// ============================================================================

// Fill in the function signature for a function that accepts rvalue reference to string:
void process_rvalue_string(std::string&& s) {
    std::cout << "Processing rvalue string: " << s << std::endl;
    // Fill in: what should we return?
    return;
}

// Fill in the function signature for a function that accepts lvalue reference to string:  
void process_lvalue_string(const std::string& s) {
    std::cout << "Processing lvalue string: " << s << std::endl;
    return;
}

void test_function_overloading() {
    std::cout << "\n=== Testing Function Overloading with References ===" << std::endl;
    
    std::string str = "test string";
    
    // This should call lvalue version:
    process_lvalue_string(str);
    
    // This should call rvalue version - fill in the function call:
    process_rvalue_string(std::move(str));
    
    // This should also call rvalue version:
    process_rvalue_string("temporary string");
}

// ============================================================================
// SECTION 6: Performance Comparison
// ============================================================================

void performance_test() {
    std::cout << "\n=== Performance Test: Copy vs Move ===" << std::endl;
    
    // Test 1: Copy construction (slow)
    {
        large_class original;
        // This will use copy constructor (copy/move)
        large_class copy_constructed(original);
    }
    
    std::cout << "\n";
    
    // Test 2: Move construction (fast)  
    {
        large_class original;
        // This will use move constructor (copy/move) 
        // Fill in the function call:
        large_class move_constructed(std::move(original));
    }
}

// ============================================================================
// MAIN TEST FUNCTION
// ============================================================================

int main() {
    std::cout << "=== rValue Quiz - Answer Version ===" << std::endl;
    
    test_basic_rvalue_concepts();
    test_reference_binding();
    test_move_semantics();
    test_string_move();
    test_unique_ptr_ownership();
    test_function_overloading();
    performance_test();
    
    std::cout << "\n=== All Tests Complete! ===" << std::endl;
    
    return 0;
}