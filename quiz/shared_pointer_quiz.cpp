/*
 * Modern C++ Shared Pointer Quiz
 * 
 * Instructions:
 * 1. Fill in the blanks marked with _______ or /* FILL HERE */
 * 2. Complete the incomplete lines and functions
 * 3. Run the test functions to validate your solutions
 * 4. Compare with the answer section at the bottom
 * 
 * Topics covered:
 * - Basic shared_ptr creation and usage
 * - make_shared vs new usage patterns
 * - Reference counting behavior
 * - enable_shared_from_this pattern
 * - Common pitfalls and best practices
 * - Memory management scenarios
 */

#include <_______>  // Include the memory header
#include <iostream>
#include <vector>
#include <cassert>

// Quiz 1: Basic shared_ptr creation
void quiz1_basic_creation() {
    std::cout << "\n=== Quiz 1: Basic shared_ptr Creation ===" << std::endl;
    
    // Create a shared_ptr to an integer with value 42
    std::_______<int> ptr1 = _______(new int(42));
    
    // Better way: Use make_shared (fill in the blank)
    std::shared_ptr<int> ptr2 = std::_______<int>(42);
    
    // Print the values
    std::cout << "ptr1 value: " << *ptr1 << std::endl;
    std::cout << "ptr2 value: " << *_____ << std::endl;
    
    // Print reference counts
    std::cout << "ptr1 use_count: " << ptr1._______ << std::endl;
    std::cout << "ptr2 use_count: " << ptr2.use_count() << std::endl;
}

// Quiz 2: Reference counting behavior
void quiz2_reference_counting() {
    std::cout << "\n=== Quiz 2: Reference Counting ===" << std::endl;
    
    std::shared_ptr<int> ptr1 = std::make_shared<int>(100);
    std::cout << "Initial use_count: " << ptr1._______() << std::endl;
    
    {
        // Create another shared_ptr pointing to the same object
        std::_______<int> ptr2 = ptr1;
        std::cout << "After copying, use_count: " << ptr1.use_count() << std::endl;
        
        // Create a third shared_ptr
        auto ptr3 = _______;  // Copy from ptr1
        std::cout << "After third copy, use_count: " << ptr1._______() << std::endl;
        
    } // ptr2 and ptr3 go out of scope here
    
    std::cout << "After scope exit, use_count: " << ptr1.use_count() << std::endl;
}

// Quiz 3: Class with shared_ptr
class _______ {  // Fill class name
private:
    std::string name;
    int value;
    
public:
    // Constructor
    Resource(const std::string& n, int v) : _______(n), value(v) {
        std::cout << "Resource " << name << " created" << std::endl;
    }
    
    // Destructor
    ~_______() {
        std::cout << "Resource " << _______ << " destroyed" << std::endl;
    }
    
    void display() const {
        std::cout << "Resource: " << name << ", Value: " << _______ << std::endl;
    }
    
    // Getter methods
    const std::string& getName() const { return _______; }
    int getValue() const { return _______; }
};

void quiz3_class_with_shared_ptr() {
    std::cout << "\n=== Quiz 3: Class with shared_ptr ===" << std::endl;
    
    // Create shared_ptr to Resource
    std::_______<Resource> res1 = std::_______<Resource>("Resource1", 10);
    res1->_______();  // Call display method
    
    // Create another pointer to the same resource
    auto res2 = _______;  // Copy from res1
    
    std::cout << "Reference count: " << res1._______() << std::endl;
    
    // Store in a vector
    std::vector<std::shared_ptr<_______>> resources;
    resources.push_back(_______);  // Add res1 to vector
    
    std::cout << "After adding to vector, count: " << res1.use_count() << std::endl;
}

// Quiz 4: enable_shared_from_this pattern
class _______ : public std::_______<_______> {  // Fill inheritance
private:
    std::string id;
    
public:
    SmartObject(const std::string& identifier) : _______(identifier) {
        std::cout << "SmartObject " << id << " created" << std::endl;
    }
    
    ~SmartObject() {
        std::cout << "SmartObject " << id << " destroyed" << std::endl;
    }
    
    // Method to get shared_ptr to this object
    std::shared_ptr<SmartObject> getSharedPtr() {
        return _______();  // Use the inherited method
    }
    
    void work() {
        std::cout << "SmartObject " << id << " is working" << std::endl;
    }
    
    const std::string& getId() const { return _______; }
};

void quiz4_enable_shared_from_this() {
    std::cout << "\n=== Quiz 4: enable_shared_from_this ===" << std::endl;
    
    // Create SmartObject using make_shared
    std::shared_ptr<_______> obj = std::_______<SmartObject>("Object1");
    
    std::cout << "Initial use_count: " << obj._______() << std::endl;
    
    // Get another shared_ptr to the same object
    std::shared_ptr<SmartObject> obj2 = obj->_______();
    
    std::cout << "After getSharedPtr(), use_count: " << obj.use_count() << std::endl;
    
    obj->work();
    obj2->_______();  // Call work method
}

// Quiz 5: Common pitfalls and best practices
void quiz5_pitfalls_and_best_practices() {
    std::cout << "\n=== Quiz 5: Pitfalls and Best Practices ===" << std::endl;
    
    // WRONG WAY - DON'T DO THIS (Uncomment to see the problem)
    /*
    Resource* raw_ptr = new Resource("BadResource", 999);
    std::shared_ptr<Resource> ptr1(raw_ptr);
    std::shared_ptr<Resource> ptr2(raw_ptr);  // DANGER: Double management!
    */
    
    // RIGHT WAY - Use make_shared
    auto ptr = std::_______<Resource>("GoodResource", 999);
    
    // Check if pointer is valid
    if (ptr) {  // or if (ptr != _______)
        ptr->display();
    }
    
    // Reset the pointer
    ptr._______();  // Releases the managed object
    
    if (!ptr) {  // or if (ptr == nullptr)
        std::cout << "Pointer is now empty" << std::endl;
    }
    
    // Create weak_ptr to avoid circular references
    std::shared_ptr<Resource> strong_ptr = std::make_shared<Resource>("WeakTest", 123);
    std::_______<Resource> weak_ptr = strong_ptr;  // Create weak_ptr
    
    std::cout << "Strong pointer use_count: " << strong_ptr._______() << std::endl;
    std::cout << "Weak pointer expired: " << weak_ptr._______() << std::endl;
    
    // Convert weak_ptr back to shared_ptr
    if (auto locked = weak_ptr._______()) {
        locked->display();
    }
}

// Quiz 6: Custom deleter
void quiz6_custom_deleter() {
    std::cout << "\n=== Quiz 6: Custom Deleter ===" << std::endl;
    
    // Custom deleter function
    auto custom_deleter = [](Resource* ptr) {
        std::cout << "Custom deleter called for " << ptr->getName() << std::endl;
        _______ ptr;  // Delete the object
    };
    
    // Create shared_ptr with custom deleter
    std::shared_ptr<Resource> ptr(_______ Resource("CustomDeleted", 456), _______);
    
    ptr->display();
    
    // When ptr goes out of scope, custom_deleter will be called
}

// Quiz 7: Array management with shared_ptr
void quiz7_array_management() {
    std::cout << "\n=== Quiz 7: Array Management ===" << std::endl;
    
    // For arrays, use custom deleter or array version
    const int size = 5;
    
    // Method 1: Custom deleter for arrays
    std::shared_ptr<int> arr1(new int[size], [](int* p) { 
        std::cout << "Deleting array with custom deleter" << std::endl;
        _______ p;  // Use array delete
    });
    
    // Method 2: Use shared_ptr<int[]> (C++17 and later)
    std::_______<int[]> arr2(new int[size]);
    
    // Initialize arrays
    for (int i = 0; i < size; ++i) {
        arr1.get()[i] = i * 10;
        _______[i] = i * 20;  // Access arr2 elements
    }
    
    // Print arrays
    std::cout << "arr1: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr1._______()[i] << " ";  // Use get() method
    }
    std::cout << std::endl;
    
    std::cout << "arr2: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;
}

// Test function to validate solutions
void run_tests() {
    std::cout << "\n=== Running Tests ===" << std::endl;
    
    // Test basic functionality
    try {
        quiz1_basic_creation();
        quiz2_reference_counting();
        quiz3_class_with_shared_ptr();
        quiz4_enable_shared_from_this();
        quiz5_pitfalls_and_best_practices();
        quiz6_custom_deleter();
        quiz7_array_management();
        
        std::cout << "\n✅ All tests completed successfully!" << std::endl;
    } catch (const std::exception& e) {
        std::cout << "❌ Test failed with exception: " << e.what() << std::endl;
    }
}

int main() {
    std::cout << "Modern C++ Shared Pointer Quiz" << std::endl;
    std::cout << "==============================" << std::endl;
    
    // Uncomment the following line after filling in the blanks
    // run_tests();
    
    std::cout << "\nQuiz completed! Check the answer section below." << std::endl;
    return 0;
}

/*
 * ========================================
 * ANSWER SECTION - DO NOT LOOK UNTIL YOU'VE TRIED!
 * ========================================
 * 
 * Quiz 1 Answers:
 * - #include <memory>
 * - std::shared_ptr<int> ptr1 = std::shared_ptr<int>(new int(42));
 * - std::shared_ptr<int> ptr2 = std::make_shared<int>(42);
 * - *ptr2
 * - ptr1.use_count()
 * 
 * Quiz 2 Answers:
 * - ptr1.use_count()
 * - std::shared_ptr<int> ptr2 = ptr1;
 * - auto ptr3 = ptr1;
 * - ptr1.use_count()
 * 
 * Quiz 3 Answers:
 * - class Resource
 * - name(n)
 * - ~Resource()
 * - name
 * - value
 * - name
 * - value
 * - std::shared_ptr<Resource> res1 = std::make_shared<Resource>("Resource1", 10);
 * - res1->display();
 * - auto res2 = res1;
 * - res1.use_count()
 * - std::shared_ptr<Resource>
 * - res1
 * 
 * Quiz 4 Answers:
 * - class SmartObject : public std::enable_shared_from_this<SmartObject>
 * - std::enable_shared_from_this<SmartObject>
 * - SmartObject
 * - id(identifier)
 * - shared_from_this()
 * - id
 * - std::shared_ptr<SmartObject> obj = std::make_shared<SmartObject>("Object1");
 * - obj.use_count()
 * - obj->getSharedPtr()
 * - obj2->work()
 * 
 * Quiz 5 Answers:
 * - std::make_shared<Resource>("GoodResource", 999)
 * - nullptr
 * - ptr.reset()
 * - std::weak_ptr<Resource> weak_ptr = strong_ptr;
 * - strong_ptr.use_count()
 * - weak_ptr.expired()
 * - weak_ptr.lock()
 * 
 * Quiz 6 Answers:
 * - delete ptr;
 * - new Resource("CustomDeleted", 456)
 * - custom_deleter
 * 
 * Quiz 7 Answers:
 * - delete[] p;
 * - std::shared_ptr<int[]> arr2(new int[size]);
 * - arr2[i]
 * - arr1.get()[i]
 */