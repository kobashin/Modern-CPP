# Modern C++ Shared Pointer Quiz

This quiz is designed to help you review and practice key concepts related to `std::shared_ptr` in Modern C++.

## Files

- `shared_pointer_quiz.cpp` - The main quiz file with blanks to fill in
- `shared_pointer_quiz_solution.cpp` - Complete solution with all blanks filled
- `README.md` - This instruction file

## How to Use

1. **Fill in the blanks**: Open `shared_pointer_quiz.cpp` and fill in all the blanks marked with `_______` or `/* FILL HERE */`

2. **Compile and test**: 
   ```bash
   g++ -std=c++17 shared_pointer_quiz.cpp -o shared_pointer_quiz
   ./shared_pointer_quiz
   ```

3. **Enable tests**: After filling in the blanks, uncomment the `run_tests();` line in the main function to validate your solutions

4. **Check your answers**: Compare your solutions with the answer section at the bottom of the quiz file

## Topics Covered

The quiz covers these essential shared_ptr concepts:

### Quiz 1: Basic shared_ptr Creation
- Creating shared_ptr instances
- Difference between `shared_ptr` constructor and `make_shared`
- Basic pointer dereferencing
- Reference counting basics

### Quiz 2: Reference Counting Behavior
- Understanding `use_count()` method
- How reference counting changes with copying
- Scope-based automatic cleanup

### Quiz 3: Class with shared_ptr
- Using shared_ptr with custom classes
- Constructor and destructor behavior
- Storing shared_ptr in containers
- Method calls through shared_ptr

### Quiz 4: enable_shared_from_this Pattern
- Inheriting from `std::enable_shared_from_this`
- Using `shared_from_this()` method
- Safe creation of additional shared_ptr instances

### Quiz 5: Common Pitfalls and Best Practices
- Avoiding double management errors
- Proper pointer validation
- Using `reset()` method
- Understanding `weak_ptr` and circular references
- Converting between weak_ptr and shared_ptr

### Quiz 6: Custom Deleter
- Creating and using custom deleters
- Lambda functions as deleters
- Understanding when custom deleters are called

### Quiz 7: Array Management
- Managing arrays with shared_ptr
- Custom deleters for arrays vs `shared_ptr<T[]>`
- Proper array deletion with `delete[]`

## Requirements Met

✅ **50+ blank lines**: The quiz contains over 70 blank spaces and incomplete lines  
✅ **Based on test files**: Content derived from `test_shared_pointer.cpp` and `test_shared_from_this.cpp`  
✅ **Answer section**: Complete answers provided at the bottom of the quiz file  
✅ **Test functions**: `run_tests()` function validates the solutions  
✅ **Key language specifications**: Covers essential shared_ptr concepts and patterns  

## Expected Learning Outcomes

After completing this quiz, you should understand:

- When and why to use `std::shared_ptr`
- The difference between `make_shared` and direct construction
- How reference counting works in shared_ptr
- The `enable_shared_from_this` pattern and its use cases
- Common pitfalls and how to avoid them
- Best practices for memory management with shared_ptr
- How to work with arrays and custom deleters

## Compilation Requirements

- C++11 or later (C++17 recommended for full feature support)
- Standard library with `<memory>` header support

## Notes

- The quiz is designed to be progressively challenging
- Each section builds upon previous concepts
- Real-world scenarios are used to demonstrate practical usage
- All code examples are compilable and runnable when completed correctly