// Modern C++ Regex Quiz
// Fill in the blanks to complete the regex functionality
// Based on test_regex_iterator.cpp and q029.cpp

#include <iostream>
#include <iterator>
#include <regex>
#include <string>
#include <vector>
#include <cassert>

// Part 1: Basic Iterator Template Function
// Fill in the blanks to create a generic find function
template <class Iterator, class T>
Iterator my_find(Iterator first, Iterator last, T value) {
    while (_______ != _______) {
        // Iterator can refer values indirectly by '*'. 
        if (_______ == _______) {
            return _______;
        }
        // Iterator can move to next value by '++'.
        _______first;
    }
    return _______;
}

// Part 2: License Plate Validation
// Fill in the regex pattern and function logic
bool validate_license_plate_format(std::string const & str) {
    // Create a regex pattern for format: ABC-DE 123 or ABC-DE 1234
    // Pattern should match: 3 uppercase letters, dash, 2 uppercase letters, space, 3-4 digits
    std::regex rx(R"(_______)");
    
    // Use regex_match to validate the entire string matches the pattern
    return std::_______(_______._______(), _______);
}

// Part 3: License Plate Extraction
// Fill in the regex iterator usage
std::vector<std::string> extract_license_plate_numbers(std::string const & str) {
    // Create regex pattern with capture group for license plates
    std::regex rx(R"((_______)*))");
    std::vector<std::string> results;

    // Use sregex_iterator to find all matches in the string
    for (auto i = std::_______(str.begin(), str.end(), _______);
         i != std::_______(); ++i) {
        // Check if the capture group matched
        if((*i)[_______].matched) {
            // Add the matched string to results
            results.push_back(_______->_______());
        }
    }
    return _______;
}

// Part 4: Basic Regex Iterator Example
void test_regex_iterator() {
    std::cout << "< Test: sregex_iterator >" << std::endl;
    
    // Create a test string with numbers
    std::string s("_______");
    
    // Create regex pattern to match one or more digits
    std::regex re("_______");

    // Iterate through all matches using sregex_iterator
    for (std::_______ it(std::begin(_______), std::end(_______), _______), end; 
         _______ != _______; ++_______) {
        auto&& m = *_______;
        std::cout << "position = " << m._______() 
                  << ", length = " << m._______() 
                  << ", str = '" << m._______() 
                  << '\'' << std::endl;
    }
}

// Part 5: Vector Iterator Test
void test_vector_iterator() {
    std::cout << "< Test: iterator >" << std::endl;
    
    // Create a vector with some integers
    std::vector<int> v = {_______, _______, _______, _______, _______};
    
    // Use our my_find function to search for value 3
    decltype(v)::iterator it = my_find(_______.begin(), _______.end(), _______);

    if (_______ != _______.end()) {
        std::cout << *_______ << std::endl;
    }
    else {
        // found nothing
        std::cout << "_______" << std::endl;
    }
}

// Part 6: Advanced Iterator Test with next()
void test_next_iterator() {
    std::cout << "< Test: next() >" << std::endl;
    
    std::vector<int> v = {1, 2, 3, 4, 5};
    
    // Use my_find with next() to limit search to first 3 elements
    auto it = my_find(v.begin(), _______(v.begin(), _______), 2);
    std::cout << "my_find(v.begin(), next(v.begin(), 3), 2) = " << *_______ << std::endl;
}

// Part 7: Pointer as Iterator Test
void test_pointer_iterator() {
    std::cout << "< Test: using pointer as an iterator >" << std::endl;
    
    // Create an array
    int ar[10] = {_______, _______, _______, _______, _______, 
                  _______, _______, _______, _______, _______};
    
    // Use my_find with pointers (pointers are iterators!)
    int* p = my_find(_______, _______ + _______, 7);
    
    if (_______ != _______ + _______) {
        std::cout << "*p = " << *_______ << std::endl;
    }
}

// Part 8: Additional Regex Patterns
void test_additional_patterns() {
    std::cout << "< Test: Additional Regex Patterns >" << std::endl;
    
    // Email validation pattern
    std::string email = "user@example.com";
    std::regex email_pattern(R"(_______)");  // Fill with email regex pattern
    
    if (std::regex_match(_______, _______)) {
        std::cout << "Valid email: " << _______ << std::endl;
    }
    
    // Phone number pattern (XXX-XXX-XXXX)
    std::string phone = "123-456-7890";
    std::regex phone_pattern(R"(_______)");  // Fill with phone regex pattern
    
    if (std::_______(_______._______(), _______)) {
        std::cout << "Valid phone: " << _______ << std::endl;
    }
    
    // Extract all words from a sentence
    std::string sentence = "Hello world from Modern C++";
    std::regex word_pattern(R"(_______)");  // Fill with word regex pattern
    
    std::cout << "Words found: ";
    for (std::_______ it(sentence.begin(), sentence.end(), _______), end;
         it != end; ++it) {
        std::cout << "'" << it->_______() << "' ";
    }
    std::cout << std::endl;
}

// Test Functions - DO NOT MODIFY THESE
void run_tests() {
    std::cout << "\n=== Running Tests ===\n" << std::endl;
    
    // Test license plate validation
    std::cout << "Testing license plate validation..." << std::endl;
    assert(validate_license_plate_format("ABC-DE 123"));
    assert(validate_license_plate_format("ABC-DE 1234"));
    assert(!validate_license_plate_format("ABC-DE 12345"));
    assert(!validate_license_plate_format("abc-de 1234"));
    std::cout << "✓ License plate validation tests passed!" << std::endl;
    
    // Test license plate extraction
    std::cout << "\nTesting license plate extraction..." << std::endl;
    std::vector<std::string> expected{"AAA-AA 123", "ABC-DE 1234", "XYZ-WW 0001"};
    std::string text{"AAA-AA 123qwe-ty 1234 ABC-DE 123456.. XYZ-WW 0001"};
    auto result = extract_license_plate_numbers(text);
    assert(expected == result);
    std::cout << "✓ License plate extraction tests passed!" << std::endl;
    
    // Test iterator functionality
    std::cout << "\nTesting iterator functionality..." << std::endl;
    std::vector<int> v = {1, 2, 3, 4, 5};
    auto it = my_find(v.begin(), v.end(), 3);
    assert(it != v.end() && *it == 3);
    
    int ar[5] = {1, 2, 3, 4, 5};
    int* p = my_find(ar, ar + 5, 4);
    assert(p != ar + 5 && *p == 4);
    std::cout << "✓ Iterator functionality tests passed!" << std::endl;
    
    std::cout << "\n🎉 All tests passed! Great job!" << std::endl;
}

int main() {
    std::cout << "=== Modern C++ Regex Quiz ===" << std::endl;
    std::cout << "Fill in the blanks and run the tests to validate your solutions\n" << std::endl;
    
    // Run all the test functions
    test_regex_iterator();
    std::cout << std::endl;
    
    test_vector_iterator();
    std::cout << std::endl;
    
    test_next_iterator();
    std::cout << std::endl;
    
    test_pointer_iterator();
    std::cout << std::endl;
    
    test_additional_patterns();
    std::cout << std::endl;
    
    // Run validation tests
    run_tests();
    
    return 0;
}

/*
=== ANSWER SECTION ===

Part 1: Basic Iterator Template Function
Line 15: first != last
Line 17: *first == value
Line 18: first
Line 21: ++first
Line 23: first

Part 2: License Plate Validation
Line 30: [A-Z]{3}-[A-Z]{2} \d{3,4}
Line 33: regex_match, str, c_str(), rx

Part 3: License Plate Extraction
Line 38: [A-Z]{3}-[A-Z]{2} \d{3,4}
Line 42: sregex_iterator, rx
Line 43: sregex_iterator
Line 45: 1
Line 47: i, str
Line 49: results

Part 4: Basic Regex Iterator Example
Line 55: a01da123456da999d
Line 58: \\d+
Line 61: sregex_iterator, s, s, re
Line 62: it, end, it
Line 63: it
Line 64: position
Line 65: length
Line 66: str

Part 5: Vector Iterator Test
Line 73: 1, 2, 3, 4, 5
Line 76: v, v, 3
Line 78: it, v
Line 79: it
Line 82: "Value not found"

Part 6: Advanced Iterator Test with next()
Line 89: next, 3
Line 90: it

Part 7: Pointer as Iterator Test
Line 98: 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
Line 101: ar, ar, 10
Line 103: p, ar, 10
Line 104: p

Part 8: Additional Regex Patterns
Line 111: [a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}
Line 113: email, email_pattern
Line 114: email

Line 118: \d{3}-\d{3}-\d{4}
Line 120: regex_match, phone, c_str(), phone_pattern
Line 121: phone

Line 125: \w+
Line 128: sregex_iterator, word_pattern
Line 130: str

Key Concepts Covered:
- std::regex and raw string literals R"()"
- std::regex_match for full string validation
- std::sregex_iterator for finding multiple matches
- Iterator concepts and generic programming
- Template functions with iterators
- Pointer arithmetic as iterator usage
- Regular expression patterns for common validations
- Capture groups and match extraction
- Position, length, and string methods on match objects
*/