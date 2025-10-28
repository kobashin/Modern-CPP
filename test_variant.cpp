#include <variant>
#include <iostream>

// Simple debug logging macro
#define DEBUG_LOG(msg) std::cout << "[DEBUG] " << msg << std::endl

struct A {void f() { std::cout << "A.f()" << std::endl; }};
struct B {void f() { std::cout << "B.f()" << std::endl; }};
struct C {void f() { std::cout << "C.f()" << std::endl; }};

void  cppref_example() {

    // https://cpprefjp.github.io/reference/variant/variant.html

    // a variant type to which A, B, or C can be assigned
    std::variant<A, B, C> v = A{};
    v = B{};

    /*
        std::holds_alternative

        check if v has B-type object
        https://cpprefjp.github.io/reference/variant/holds_alternative.html
    */
    if (std::holds_alternative<B>(v)) {
        B& b = std::get<B>(v);
        (void)b;
    }

    /*
        std::visit
    
        calls the common interface even if any type is assigned to v.
        std::visit calls the function corresponding to the variant object

        https://cpprefjp.github.io/reference/variant/visit.html
    */
    std::visit(
        [](auto& x) { x.f(); }, 
        v
    );
}

void pocket_reference_example() {

    // p344
    DEBUG_LOG("=== pocket_reference_example() start ===");

    DEBUG_LOG("Creating variant<int, char, string> with int value 3");
    std::variant<int, char, std::string> v = 3;
    
    DEBUG_LOG("Variant created successfully");
    DEBUG_LOG("Current variant index: " << v.index());
    DEBUG_LOG("Variant holds int: " << std::holds_alternative<int>(v));
    DEBUG_LOG("Variant holds char: " << std::holds_alternative<char>(v));
    DEBUG_LOG("Variant holds string: " << std::holds_alternative<std::string>(v));
    
    DEBUG_LOG("Extracting int value using std::get<int>(v)");
    int n = std::get<int>(v);
    
    DEBUG_LOG("Extraction successful");
    std::cout << "int value: " << n << std::endl;
    
    DEBUG_LOG("=== pocket_reference_example() end ===");

}

int main() {
    cppref_example();
    pocket_reference_example();
}