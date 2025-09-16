# rValue Quiz

This quiz helps you review rValue and move semantics concepts in Modern C++.

## Files

- `rValue_quiz.cpp` - The main quiz file with blanks to fill in
- `rValue_quiz_complete_answers.cpp` - Complete working version with all answers

## How to Use

### Taking the Quiz

1. Open `rValue_quiz.cpp` 
2. Fill in the blanks marked with:
   - `_______` (underscores)
   - `/* FILL_IN_TYPE */` comments
   - `/* BLANK */` comments
3. Try to compile and run to test your answers:
   ```bash
   g++ -std=c++11 -o rValue_quiz rValue_quiz.cpp
   ./rValue_quiz
   ```
4. Fix compilation errors by filling in the correct code
5. Compare with the answer section at the bottom of the file

### Checking Answers

- The answer section is included at the bottom of `rValue_quiz.cpp`
- You can also refer to `rValue_quiz_complete_answers.cpp` for the complete working solution

## Topics Covered

The quiz covers 10 major sections of rValue and move semantics:

1. **Basic rValue Concepts** - lvalue vs rvalue identification
2. **Reference Types** - lvalue references (`T&`) vs rvalue references (`T&&`)
3. **Move Constructor and Move Semantics** - implementing move constructors and assignment operators
4. **std::move and Ownership Transfer** - using `std::move()` function
5. **Advanced Move Scenarios** - function overloading with references
6. **Performance Comparison** - copy vs move performance implications
7. **Template Functions and Universal References** - `T&&` in template contexts
8. **Perfect Forwarding** - `std::forward()` usage
9. **Advanced Move Scenarios** - complex resource management with move semantics
10. **Value Categories** - lvalue, prvalue, and xvalue classifications

## Learning Objectives

After completing this quiz, you should understand:

- The difference between lvalues and rvalues
- When and how to use rvalue references (`T&&`)
- How to implement move constructors and move assignment operators
- When `std::move()` is needed and how it works
- Universal references in template functions
- Perfect forwarding with `std::forward()`
- Value categories in C++11 and later
- Performance benefits of move semantics
- Reference binding rules and constraints

## Requirements Met

This quiz meets all the specified requirements:

- ✅ Content based on existing `test_rValues_*.cpp` files
- ✅ More than 50 blank lines/holes to fill (82 total blanks)
- ✅ Comprehensive answer section included
- ✅ Test functions that can be run to validate answers
- ✅ Covers key rValue specifications of C++

## Compilation Requirements

- C++11 compatible compiler
- Standard library support for `<utility>`, `<memory>`, `<string>`, etc.

Example compilation:
```bash
g++ -std=c++11 -Wall -o rValue_quiz rValue_quiz.cpp
```