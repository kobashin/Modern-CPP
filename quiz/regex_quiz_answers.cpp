// Modern C++ Regex Quiz - ANSWER VERSION
// This is the completed version for validation
// Based on test_regex_iterator.cpp and q029.cpp

#include <iostream>
#include <iterator>
#include <regex>
#include <string>
#include <vector>
#include <cassert>

// Part 1: Basic Iterator Template Function
template <class Iterator, class T>
Iterator my_find(Iterator first, Iterator last, T value) {
    while (first != last) {
        // Iterator can refer values indirectly by '*'. 
        if (*first == value) {
            return first;
        }
        // Iterator can move to next value by '++'.
        ++first;
    }
    return first;
}

// Part 2: License Plate Validation
bool validate_license_plate_format(std::string const & str) {
    // Create a regex pattern for format: ABC-DE 123 or ABC-DE 1234
    std::regex rx(R"([A-Z]{3}-[A-Z]{2} \d{3,4})");
    
    // Use regex_match to validate the entire string matches the pattern
    return std::regex_match(str.c_str(), rx);
}

// Part 3: License Plate Extraction
std::vector<std::string> extract_license_plate_numbers(std::string const & str) {
    // Create regex pattern with capture group for license plates
    std::regex rx(R"(([A-Z]{3}-[A-Z]{2} \d{3,4})*)");
    std::vector<std::string> results;

    // Use sregex_iterator to find all matches in the string
    for (auto i = std::sregex_iterator(str.begin(), str.end(), rx);
         i != std::sregex_iterator(); ++i) {
        // Check if the capture group matched
        if((*i)[1].matched) {
            // Add the matched string to results
            results.push_back(i->str());
        }
    }
    return results;
}

// Part 4: Basic Regex Iterator Example
void test_regex_iterator() {
    std::cout << "< Test: sregex_iterator >" << std::endl;
    
    // Create a test string with numbers
    std::string s("a01da123456da999d");
    
    // Create regex pattern to match one or more digits
    std::regex re("\\d+");

    // Iterate through all matches using sregex_iterator
    for (std::sregex_iterator it(std::begin(s), std::end(s), re), end; 
         it != end; ++it) {
        auto&& m = *it;
        std::cout << "position = " << m.position() 
                  << ", length = " << m.length() 
                  << ", str = '" << m.str() 
                  << '\'' << std::endl;
    }
}

// Part 5: Vector Iterator Test
void test_vector_iterator() {
    std::cout << "< Test: iterator >" << std::endl;
    
    // Create a vector with some integers
    std::vector<int> v = {1, 2, 3, 4, 5};
    
    // Use our my_find function to search for value 3
    decltype(v)::iterator it = my_find(v.begin(), v.end(), 3);

    if (it != v.end()) {
        std::cout << *it << std::endl;
    }
    else {
        // found nothing
        std::cout << "Value not found" << std::endl;
    }
}

// Part 6: Advanced Iterator Test with next()
void test_next_iterator() {
    std::cout << "< Test: next() >" << std::endl;
    
    std::vector<int> v = {1, 2, 3, 4, 5};
    
    // Use my_find with next() to limit search to first 3 elements
    auto it = my_find(v.begin(), next(v.begin(), 3), 2);
    std::cout << "my_find(v.begin(), next(v.begin(), 3), 2) = " << *it << std::endl;
}

// Part 7: Pointer as Iterator Test
void test_pointer_iterator() {
    std::cout << "< Test: using pointer as an iterator >" << std::endl;
    
    // Create an array
    int ar[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // Use my_find with pointers (pointers are iterators!)
    int* p = my_find(ar, ar + 10, 7);
    
    if (p != ar + 10) {
        std::cout << "*p = " << *p << std::endl;
    }
}

// Part 8: Additional Regex Patterns
void test_additional_patterns() {
    std::cout << "< Test: Additional Regex Patterns >" << std::endl;
    
    // Email validation pattern
    std::string email = "user@example.com";
    std::regex email_pattern(R"([a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,})");
    
    if (std::regex_match(email, email_pattern)) {
        std::cout << "Valid email: " << email << std::endl;
    }
    
    // Phone number pattern (XXX-XXX-XXXX)
    std::string phone = "123-456-7890";
    std::regex phone_pattern(R"(\d{3}-\d{3}-\d{4})");
    
    if (std::regex_match(phone.c_str(), phone_pattern)) {
        std::cout << "Valid phone: " << phone << std::endl;
    }
    
    // Extract all words from a sentence
    std::string sentence = "Hello world from Modern C++";
    std::regex word_pattern(R"(\w+)");
    
    std::cout << "Words found: ";
    for (std::sregex_iterator it(sentence.begin(), sentence.end(), word_pattern), end;
         it != end; ++it) {
        std::cout << "'" << it->str() << "' ";
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
    std::cout << "=== Modern C++ Regex Quiz - ANSWER VERSION ===" << std::endl;
    std::cout << "This demonstrates the completed solutions\n" << std::endl;
    
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