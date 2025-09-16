/*
    rValue Quiz - Review rValue and Move Semantics in Modern C++
    
    Instructions:
    Fill in the blanks marked with ______ or BLANK comments
    Replace template comments with appropriate types and code
    Compile and run to test your answers
    Check against the answer section at the bottom
    
    To compile: g++ -std=c++11 -o rValue_quiz rValue_quiz.cpp
    To run: ./rValue_quiz
    
    Topics covered:
    lvalue vs rvalue concepts
    lvalue and rvalue references  
    Move constructors and move assignment operators
    std::move() function
    Reference binding constraints
    Move semantics for performance optimization
    Ownership transfer
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
    i;      // Named objects are _______ values (lvalue/rvalue)
    0;      // Literal values are _______ values (lvalue/rvalue) 

    Foo x;
    x;      // Named objects are _______ values (lvalue/rvalue)
    Foo();  // Constructor return values are _______ values (lvalue/rvalue)

    f();    // Function return values are _______ values (lvalue/rvalue)
    
    std::cout << "Basic rValue concepts test completed." << std::endl;
}

// ============================================================================
// SECTION 2: Reference Types and Binding Constraints  
// ============================================================================

void test_reference_binding() {
    std::cout << "\n=== Testing Reference Binding ===" << std::endl;
    
    int x = 0;

    // Fill in the reference types:
    /* FILL_IN_TYPE */& lvalue_ref_1 = x;          // lvalue reference type
    // int& lvalue_ref_error = 0;                  // Error: cannot bind rvalue to lvalue reference
    
    // /* FILL_IN_TYPE */ rvalue_ref_error = x;     // Error: cannot bind lvalue to rvalue reference  
    /* FILL_IN_TYPE */&& rvalue_ref_1 = 0;        // rvalue reference type

    // const lvalue reference - special case
    const /* FILL_IN_TYPE */& const_lvalue_ref_1 = x;    // can bind lvalue
    const /* FILL_IN_TYPE */& const_lvalue_ref_2 = 0;    // can also bind _______ (lvalue/rvalue)
    
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
            std::cout << "[_______ constructor]" << std::endl;  // Fill in constructor type
        }

        // Copy constructor - takes const reference to same class
        large_class(const /* FILL_IN_TYPE */& r) {
            ptr = new char[1000];
            std::copy(r.ptr, r.ptr + 1000, ptr);
            std::cout << "[_______ constructor]" << std::endl;  // Fill in constructor type
        }

        // Destructor
        ~large_class() {
            delete[] ptr;
            std::cout << "[_______]" << std::endl;  // Fill in what this is
        }

        // Move constructor - takes rvalue reference
        large_class(/* FILL_IN_TYPE */&& r) {
            // Transfer ownership - fill in the implementation
            ptr = _______;        // Transfer pointer
            r.ptr = _______;      // Set original to safe state
            std::cout << "[_______ constructor]" << std::endl;  // Fill in constructor type
        }

        // Move assignment operator
        large_class& operator=(/* FILL_IN_TYPE */&& r) {
            // Clean up existing resource
            delete[] ptr;
            
            // Transfer ownership - fill in the implementation  
            ptr = _______;        // Transfer pointer
            r.ptr = _______;      // Set original to safe state
            std::cout << "[_______ operator=]" << std::endl;  // Fill in operator type
            
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
    
    // This will call _______ constructor (copy/move)
    large_class z(y);

    // Using std::move to force move constructor
    // Fill in the function that converts lvalue to rvalue:
    large_class x(_______::______(tmp));
    
    // Using std::move for move assignment
    // Fill in the function call:
    y = _______::______(x);
    
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
    std::_______(x); // Function name - Nothing happens because result is not _______
    
    // This actually moves the string - fill in the function:
    std::string y = std::_______(x);
    
    std::cout << "x after move: '" << x << "'" << std::endl;
    std::cout << "y after move: '" << y << "'" << std::endl;
}

void test_unique_ptr_ownership() {
    std::cout << "\n=== Testing Unique Pointer Ownership Transfer ===" << std::endl;
    
    // Create unique_ptr - fill in template parameter type:
    std::unique_ptr</* FILL_IN_TYPE */> p(new int(1));
    
    std::cout << "p points to: " << (p ? "valid object" : "nullptr") << std::endl;
    std::cout << "Value: " << (p ? *p : 0) << std::endl;
    
    // Transfer ownership - fill in the function call:
    std::unique_ptr<int> q = _______::______(p);
    
    std::cout << "After ownership transfer:" << std::endl;
    std::cout << "p points to: " << (p ? "valid object" : "nullptr") << std::endl;  
    std::cout << "q points to: " << (q ? "valid object" : "nullptr") << std::endl;
    std::cout << "Value in q: " << (q ? *q : 0) << std::endl;
}

// ============================================================================
// SECTION 5: Advanced Move Scenarios
// ============================================================================

// Fill in the function signature for a function that accepts rvalue reference to string:
/* FILL_IN_RETURN_TYPE */ process_rvalue_string(/* FILL_IN_PARAMETER_TYPE */) {
    std::cout << "Processing rvalue string: " << s << std::endl;
    // Fill in: what should we return?
    return /* BLANK */;
}

// Fill in the function signature for a function that accepts lvalue reference to string:  
/* FILL_IN_RETURN_TYPE */ process_lvalue_string(/* FILL_IN_PARAMETER_TYPE */) {
    std::cout << "Processing lvalue string: " << s << std::endl;
    return /* BLANK */;
}

void test_function_overloading() {
    std::cout << "\n=== Testing Function Overloading with References ===" << std::endl;
    
    std::string str = "test string";
    
    // This should call lvalue version:
    process_lvalue_string(str);
    
    // This should call rvalue version - fill in the function call:
    process_rvalue_string(_______::______(str));
    
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
        // This will use _______ constructor (copy/move)
        large_class copy_constructed(original);
    }
    
    std::cout << "\n";
    
    // Test 2: Move construction (fast)  
    {
        large_class original;
        // This will use _______ constructor (copy/move) 
        // Fill in the function call:
        large_class move_constructed(_______::______(original));
    }
}

// ============================================================================
// SECTION 7: Template Functions and Universal References
// ============================================================================

template<typename T>
void process_universal_ref(/* FILL_IN_TYPE */) {
    std::cout << "Processing universal reference" << std::endl;
    // Fill in: what happens when T&& is used in template?
    // Answer: It becomes a _______ reference when used in templates
}

void test_universal_references() {
    std::cout << "\n=== Testing Universal References ===" << std::endl;
    
    int x = 42;
    
    // These calls will deduce different types:
    process_universal_ref(x);           // T deduced as _______&
    process_universal_ref(100);         // T deduced as _______
    process_universal_ref(std::move(x)); // T deduced as _______
}

// ============================================================================
// SECTION 8: Perfect Forwarding
// ============================================================================

template<typename T>
void forward_to_function(T&& arg) {
    // Fill in: How to perfectly forward the argument?
    process_universal_ref(_______::_______(arg));
}

void test_perfect_forwarding() {
    std::cout << "\n=== Testing Perfect Forwarding ===" << std::endl;
    
    int value = 123;
    
    // Test forwarding lvalue:
    forward_to_function(value);
    
    // Test forwarding rvalue:
    forward_to_function(456);
    
    // Test forwarding moved value:
    forward_to_function(std::move(value));
}

// ============================================================================
// SECTION 9: Advanced Move Scenarios
// ============================================================================

class Resource {
private:
    std::string name;
    int* data;
    size_t size;
    
public:
    // Default constructor
    Resource(const std::string& n = "default") : name(n), data(nullptr), size(0) {
        std::cout << "[Resource " << name << " _______ constructor]" << std::endl;
    }
    
    // Constructor with size
    Resource(const std::string& n, size_t s) : name(n), size(s) {
        data = new int[size];
        std::cout << "[Resource " << name << " _______ constructor with size " << size << "]" << std::endl;
    }
    
    // Copy constructor
    Resource(const /* FILL_IN_TYPE */& other) : name(other.name + "_copy"), size(other.size) {
        if (size > 0) {
            data = new int[size];
            std::copy(other.data, other.data + size, data);
        } else {
            data = nullptr;
        }
        std::cout << "[Resource " << name << " _______ constructor]" << std::endl;
    }
    
    // Move constructor  
    Resource(/* FILL_IN_TYPE */&& other) noexcept : name(std::move(other.name) + "_moved"), size(other.size) {
        // Transfer ownership
        data = _______;
        
        // Reset source object
        other.data = _______;
        other.size = _______;
        other.name = "_______";
        
        std::cout << "[Resource " << name << " _______ constructor]" << std::endl;
    }
    
    // Copy assignment operator
    Resource& operator=(const /* FILL_IN_TYPE */& other) {
        if (this != &other) {
            // Clean up existing resources
            delete[] data;
            
            // Copy data
            name = other.name + "_______";
            size = other.size;
            if (size > 0) {
                data = new int[size];
                std::copy(other.data, other.data + size, data);
            } else {
                data = nullptr;
            }
        }
        std::cout << "[Resource " << name << " _______ assignment]" << std::endl;
        return *this;
    }
    
    // Move assignment operator
    Resource& operator=(/* FILL_IN_TYPE */&& other) noexcept {
        if (this != &other) {
            // Clean up existing resources
            delete[] data;
            
            // Move data
            name = _______::______(other.name) + "_moved_assigned";
            size = other.size;
            data = _______;
            
            // Reset source
            other.data = _______;
            other.size = _______;
            other.name = "_______";
        }
        std::cout << "[Resource " << name << " _______ assignment]" << std::endl;
        return *this;
    }
    
    // Destructor
    ~Resource() {
        delete[] data;
        std::cout << "[Resource " << name << " _______]" << std::endl;
    }
    
    // Helper methods
    const std::string& get_name() const { return name; }
    size_t get_size() const { return size; }
    bool is_valid() const { return data != nullptr || size == 0; }
};

void test_advanced_move_scenarios() {
    std::cout << "\n=== Testing Advanced Move Scenarios ===" << std::endl;
    
    // Test 1: Constructor calls
    Resource r1("original", 10);
    
    // This should call _______ constructor
    Resource r2(r1);
    
    // This should call _______ constructor
    Resource r3(_______::______(r1));
    
    // Test 2: Assignment calls
    Resource r4("target");
    
    // This should call _______ assignment
    r4 = r2;
    
    Resource r5("another_target"); 
    // This should call _______ assignment
    r5 = _______::______(r3);
    
    std::cout << "Final states:" << std::endl;
    std::cout << "r1: " << r1.get_name() << " (valid: " << r1.is_valid() << ")" << std::endl;
    std::cout << "r2: " << r2.get_name() << " (valid: " << r2.is_valid() << ")" << std::endl;
    std::cout << "r3: " << r3.get_name() << " (valid: " << r3.is_valid() << ")" << std::endl;
    std::cout << "r4: " << r4.get_name() << " (valid: " << r4.is_valid() << ")" << std::endl;
    std::cout << "r5: " << r5.get_name() << " (valid: " << r5.is_valid() << ")" << std::endl;
}

// ============================================================================
// SECTION 10: Value Categories Quiz
// ============================================================================

void test_value_categories() {
    std::cout << "\n=== Testing Value Categories ===" << std::endl;
    
    int x = 42;
    int y = 24;
    
    // Classify each expression as lvalue, prvalue, or xvalue:
    
    x;                    // This is an _______ (lvalue/prvalue/xvalue)
    42;                   // This is a _______ (lvalue/prvalue/xvalue)  
    x + y;                // This is a _______ (lvalue/prvalue/xvalue)
    ++x;                  // This is an _______ (lvalue/prvalue/xvalue)
    x++;                  // This is a _______ (lvalue/prvalue/xvalue)
    std::move(x);         // This is an _______ (lvalue/prvalue/xvalue)
    
    int arr[5];
    arr[0];               // This is an _______ (lvalue/prvalue/xvalue)
    
    std::string str = "hello";
    str.substr(1, 2);     // This is a _______ (lvalue/prvalue/xvalue)
    
    // Fill in the missing concepts:
    // _______ = expressions whose identity matters (can take address)
    // _______ = expressions that can be moved from (rvalue references)  
    // _______ = temporary expressions that are about to be destroyed
    
    std::cout << "Value categories test completed." << std::endl;
}

// ============================================================================
// MAIN TEST FUNCTION
// ============================================================================

int main() {
    std::cout << "=== rValue Quiz - Test Your Knowledge ===" << std::endl;
    std::cout << "Complete the blanks and run to check your answers!" << std::endl;
    
    test_basic_rvalue_concepts();
    test_reference_binding();
    test_move_semantics();
    test_string_move();
    test_unique_ptr_ownership();
    test_function_overloading();
    performance_test();
    test_universal_references();
    test_perfect_forwarding();
    test_advanced_move_scenarios();
    test_value_categories();
    
    std::cout << "\n=== Quiz Complete! ===" << std::endl;
    std::cout << "Check the answer section below to verify your solutions." << std::endl;
    
    return 0;
}

/*
================================================================================
ANSWER SECTION - Compare your answers with these solutions
================================================================================

SECTION 1: Basic rValue Concepts
- i; // Named objects are **lvalue** values  
- 0; // Literal values are **rvalue** values
- x; // Named objects are **lvalue** values
- Foo(); // Constructor return values are **rvalue** values  
- f(); // Function return values are **rvalue** values

SECTION 2: Reference Types and Binding
- int& lvalue_ref_1 = x;              // lvalue reference type
- int&& rvalue_ref_1 = 0;             // rvalue reference type  
- const int& const_lvalue_ref_1 = x;  // can bind lvalue
- const int& const_lvalue_ref_2 = 0;  // can also bind **rvalue**

SECTION 3: Move Constructor and Move Semantics
- std::cout << "[**default** constructor]"
- large_class(const **large_class**& r)
- std::cout << "[**copy** constructor]"  
- std::cout << "[**destructor**]"
- large_class(**large_class**&& r)
- ptr = **r.ptr**;        // Transfer pointer
- r.ptr = **nullptr**;    // Set original to safe state
- std::cout << "[**move** constructor]"
- large_class& operator=(**large_class**&& r)
- ptr = **r.ptr**;        // Transfer pointer  
- r.ptr = **nullptr**;    // Set original to safe state
- std::cout << "[**move** operator=]"
- large_class z(y);       // This will call **copy** constructor
- large_class x(**std**::**move**(tmp));
- y = **std**::**move**(x);

SECTION 4: std::move and Ownership Transfer
- std::**move**(x); // Nothing happens because result is not **assigned/used**
- std::string y = std::**move**(x);
- std::unique_ptr<**int**> p(new int(1));  
- std::unique_ptr<int> q = **std**::**move**(p);

SECTION 5: Advanced Move Scenarios  
- **void** process_rvalue_string(**std::string&& s**)
- return; (or return **void**;)
- **void** process_lvalue_string(**const std::string& s**)  
- return; (or return **void**;)
- process_rvalue_string(**std**::**move**(str));

SECTION 6: Performance Comparison
- large_class copy_constructed(original);      // **copy** constructor
- large_class move_constructed(**std**::**move**(original)); // **move** constructor

SECTION 7: Template Functions and Universal References  
- void process_universal_ref(**T&& t**)
- It becomes a **universal** reference when used in templates
- process_universal_ref(x);           // T deduced as **int**&
- process_universal_ref(100);         // T deduced as **int**
- process_universal_ref(std::move(x)); // T deduced as **int**

SECTION 8: Perfect Forwarding
- process_universal_ref(**std**::**forward**(arg));

SECTION 9: Advanced Move Scenarios
- std::cout << "[Resource " << name << " **default** constructor]"
- std::cout << "[Resource " << name << " **parameterized** constructor with size " << size << "]"  
- Resource(const **Resource**& other)
- std::cout << "[Resource " << name << " **copy** constructor]"
- Resource(**Resource**&& other) noexcept
- data = **other.data**;
- other.data = **nullptr**;
- other.size = **0**;
- other.name = "**moved**";
- std::cout << "[Resource " << name << " **move** constructor]"
- Resource& operator=(const **Resource**& other)
- name = other.name + "**_assigned**";
- std::cout << "[Resource " << name << " **copy** assignment]"
- Resource& operator=(**Resource**&& other) noexcept
- name = **std**::**move**(other.name) + "_moved_assigned";
- data = **other.data**;
- other.data = **nullptr**;
- other.size = **0**;
- other.name = "**moved**";
- std::cout << "[Resource " << name << " **move** assignment]"
- std::cout << "[Resource " << name << " **destructor**]"
- Resource r2(r1);              // **copy** constructor
- Resource r3(**std**::**move**(r1));    // **move** constructor
- r4 = r2;                      // **copy** assignment
- r5 = **std**::**move**(r3);            // **move** assignment

SECTION 10: Value Categories Quiz
- x;                    // This is an **lvalue**
- 42;                   // This is a **prvalue**
- x + y;                // This is a **prvalue**
- ++x;                  // This is an **lvalue**
- x++;                  // This is a **prvalue**
- std::move(x);         // This is an **xvalue**
- arr[0];               // This is an **lvalue**
- str.substr(1, 2);     // This is a **prvalue**
- **lvalues** = expressions whose identity matters (can take address)
- **xvalues** = expressions that can be moved from (rvalue references)
- **prvalues** = temporary expressions that are about to be destroyed

Key Concepts Summary:
1. **lvalue**: Named objects, can take address, appears on left side of assignment
2. **rvalue**: Temporary objects, literals, function returns, appears on right side  
3. **T&**: lvalue reference, can only bind to lvalues
4. **T&&**: rvalue reference, can only bind to rvalues
5. **const T&**: const lvalue reference, can bind to both lvalues and rvalues
6. **std::move()**: Converts lvalue to rvalue reference, enables move semantics
7. **Move constructor**: Takes T&& parameter, transfers resources instead of copying
8. **Move assignment**: operator= with T&& parameter, transfers resources
9. **Move semantics**: Optimization to avoid expensive copies by transferring ownership

================================================================================
*/