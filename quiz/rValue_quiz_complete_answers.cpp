/*
    rValue Quiz - COMPLETE ANSWER VERSION 
    This is the complete working version with all new sections
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

    i;      // Named objects are lvalue values
    0;      // Literal values are rvalue values 

    Foo x;
    x;      // Named objects are lvalue values
    Foo();  // Constructor return values are rvalue values

    f();    // Function return values are rvalue values
    
    std::cout << "Basic rValue concepts test completed." << std::endl;
}

// ============================================================================
// SECTION 2: Reference Types and Binding Constraints  
// ============================================================================

void test_reference_binding() {
    std::cout << "\n=== Testing Reference Binding ===" << std::endl;
    
    int x = 0;

    int& lvalue_ref_1 = x;
    int&& rvalue_ref_1 = 0;
    const int& const_lvalue_ref_1 = x;
    const int& const_lvalue_ref_2 = 0;    // can also bind rvalue
    
    std::cout << "Reference binding test completed." << std::endl;
}

// ============================================================================
// SECTION 3: Move Constructor and Move Semantics
// ============================================================================

class large_class {
    private:
        char* ptr;
    public:
        large_class() {
            ptr = new char[1000];
            std::cout << "[default constructor]" << std::endl;
        }

        large_class(const large_class& r) {
            ptr = new char[1000];
            std::copy(r.ptr, r.ptr + 1000, ptr);
            std::cout << "[copy constructor]" << std::endl;
        }

        ~large_class() {
            delete[] ptr;
            std::cout << "[destructor]" << std::endl;
        }

        large_class(large_class&& r) {
            ptr = r.ptr;
            r.ptr = nullptr;
            std::cout << "[move constructor]" << std::endl;
        }

        large_class& operator=(large_class&& r) {
            delete[] ptr;
            ptr = r.ptr;
            r.ptr = nullptr;
            std::cout << "[move operator=]" << std::endl;
            return *this;
        }
        
        bool is_valid() const {
            return ptr != nullptr;
        }
};

void test_move_semantics() {
    std::cout << "\n=== Testing Move Semantics ===" << std::endl;
    
    large_class tmp{};
    large_class y{};
    large_class z(y);  // copy constructor

    large_class x(std::move(tmp));
    y = std::move(x);
    
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
    std::move(x); // Nothing happens because result is not assigned
    std::string y = std::move(x);
    
    std::cout << "x after move: '" << x << "'" << std::endl;
    std::cout << "y after move: '" << y << "'" << std::endl;
}

void test_unique_ptr_ownership() {
    std::cout << "\n=== Testing Unique Pointer Ownership Transfer ===" << std::endl;
    
    std::unique_ptr<int> p(new int(1));
    
    std::cout << "p points to: " << (p ? "valid object" : "nullptr") << std::endl;
    std::cout << "Value: " << (p ? *p : 0) << std::endl;
    
    std::unique_ptr<int> q = std::move(p);
    
    std::cout << "After ownership transfer:" << std::endl;
    std::cout << "p points to: " << (p ? "valid object" : "nullptr") << std::endl;  
    std::cout << "q points to: " << (q ? "valid object" : "nullptr") << std::endl;
    std::cout << "Value in q: " << (q ? *q : 0) << std::endl;
}

// ============================================================================
// SECTION 5: Advanced Move Scenarios
// ============================================================================

void process_rvalue_string(std::string&& s) {
    std::cout << "Processing rvalue string: " << s << std::endl;
}

void process_lvalue_string(const std::string& s) {
    std::cout << "Processing lvalue string: " << s << std::endl;
}

void test_function_overloading() {
    std::cout << "\n=== Testing Function Overloading with References ===" << std::endl;
    
    std::string str = "test string";
    
    process_lvalue_string(str);
    process_rvalue_string(std::move(str));
    process_rvalue_string("temporary string");
}

// ============================================================================
// SECTION 6: Performance Comparison
// ============================================================================

void performance_test() {
    std::cout << "\n=== Performance Test: Copy vs Move ===" << std::endl;
    
    {
        large_class original;
        large_class copy_constructed(original);  // copy constructor
    }
    
    std::cout << "\n";
    
    {
        large_class original;
        large_class move_constructed(std::move(original));  // move constructor
    }
}

// ============================================================================
// SECTION 7: Template Functions and Universal References
// ============================================================================

template<typename T>
void process_universal_ref(T&& t) {
    std::cout << "Processing universal reference" << std::endl;
    // It becomes a universal reference when used in templates
}

void test_universal_references() {
    std::cout << "\n=== Testing Universal References ===" << std::endl;
    
    int x = 42;
    
    process_universal_ref(x);           // T deduced as int&
    process_universal_ref(100);         // T deduced as int
    process_universal_ref(std::move(x)); // T deduced as int
}

// ============================================================================
// SECTION 8: Perfect Forwarding
// ============================================================================

template<typename T>
void forward_to_function(T&& arg) {
    process_universal_ref(std::forward<T>(arg));
}

void test_perfect_forwarding() {
    std::cout << "\n=== Testing Perfect Forwarding ===" << std::endl;
    
    int value = 123;
    
    forward_to_function(value);
    forward_to_function(456);
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
    Resource(const std::string& n = "default") : name(n), data(nullptr), size(0) {
        std::cout << "[Resource " << name << " default constructor]" << std::endl;
    }
    
    Resource(const std::string& n, size_t s) : name(n), size(s) {
        data = new int[size];
        std::cout << "[Resource " << name << " parameterized constructor with size " << size << "]" << std::endl;
    }
    
    Resource(const Resource& other) : name(other.name + "_copy"), size(other.size) {
        if (size > 0) {
            data = new int[size];
            std::copy(other.data, other.data + size, data);
        } else {
            data = nullptr;
        }
        std::cout << "[Resource " << name << " copy constructor]" << std::endl;
    }
    
    Resource(Resource&& other) noexcept : name(std::move(other.name) + "_moved"), size(other.size) {
        data = other.data;
        other.data = nullptr;
        other.size = 0;
        other.name = "moved";
        std::cout << "[Resource " << name << " move constructor]" << std::endl;
    }
    
    Resource& operator=(const Resource& other) {
        if (this != &other) {
            delete[] data;
            name = other.name + "_assigned";
            size = other.size;
            if (size > 0) {
                data = new int[size];
                std::copy(other.data, other.data + size, data);
            } else {
                data = nullptr;
            }
        }
        std::cout << "[Resource " << name << " copy assignment]" << std::endl;
        return *this;
    }
    
    Resource& operator=(Resource&& other) noexcept {
        if (this != &other) {
            delete[] data;
            name = std::move(other.name) + "_moved_assigned";
            size = other.size;
            data = other.data;
            other.data = nullptr;
            other.size = 0;
            other.name = "moved";
        }
        std::cout << "[Resource " << name << " move assignment]" << std::endl;
        return *this;
    }
    
    ~Resource() {
        delete[] data;
        std::cout << "[Resource " << name << " destructor]" << std::endl;
    }
    
    const std::string& get_name() const { return name; }
    size_t get_size() const { return size; }
    bool is_valid() const { return data != nullptr || size == 0; }
};

void test_advanced_move_scenarios() {
    std::cout << "\n=== Testing Advanced Move Scenarios ===" << std::endl;
    
    Resource r1("original", 10);
    Resource r2(r1);                    // copy constructor
    Resource r3(std::move(r1));         // move constructor
    
    Resource r4("target");
    r4 = r2;                            // copy assignment
    
    Resource r5("another_target"); 
    r5 = std::move(r3);                 // move assignment
    
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
    
    // Classifications:
    // x;                    // lvalue
    // 42;                   // prvalue  
    // x + y;                // prvalue
    // ++x;                  // lvalue
    // x++;                  // prvalue
    // std::move(x);         // xvalue
    
    int arr[5];
    // arr[0];               // lvalue
    
    std::string str = "hello";
    // str.substr(1, 2);     // prvalue
    
    // lvalues = expressions whose identity matters (can take address)
    // xvalues = expressions that can be moved from (rvalue references)  
    // prvalues = temporary expressions that are about to be destroyed
    
    std::cout << "Value categories test completed." << std::endl;
}

// ============================================================================
// MAIN TEST FUNCTION
// ============================================================================

int main() {
    std::cout << "=== rValue Quiz - Complete Answer Version ===" << std::endl;
    
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
    
    std::cout << "\n=== All Tests Complete! ===" << std::endl;
    
    return 0;
}