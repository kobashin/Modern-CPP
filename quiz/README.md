# Variadic Template Quiz

## Overview
This quiz is designed to help you review and practice variadic template concepts in Modern C++. It covers key language specifications including parameter packs, folding expressions, perfect forwarding, and advanced template patterns.

## Files
- `variadic_template_quiz.cpp` - The main quiz file with blanks to fill in
- `variadic_template_quiz_answers.cpp` - Complete solution file for reference

## Quiz Content
The quiz covers 8 main sections:

1. **Basic Variadic Template Function** - Recursive template instantiation
2. **Folding Expressions (C++17)** - Modern syntax for parameter pack operations
3. **Container Operations** - Generic functions working with STL containers
4. **Advanced Patterns** - contains_any/all functions with recursive templates
5. **Perfect Forwarding** - Preserving value categories in template functions
6. **Variadic Macros** - Preprocessor macros with variable arguments
7. **Type Traits** - Compile-time type checking with variadic templates
8. **Variadic Class Template** - A simple tuple-like implementation

## How to Use

### Step 1: Take the Quiz
1. Open `variadic_template_quiz.cpp`
2. Fill in the blanks marked with `_______` or `/* BLANK */`
3. Some complete lines are missing - add them where indicated
4. The quiz has over 50 blanks to complete

### Step 2: Compile and Test
```bash
g++ -std=c++17 variadic_template_quiz.cpp -o quiz
./quiz
```

### Step 3: Verify Your Solution
If all test functions pass, your answers are correct! The program will show:
- ✅ Individual test results for each section
- 🎉 Success message if everything works

### Step 4: Check Answers (if needed)
If you get stuck, refer to `variadic_template_quiz_answers.cpp` or the answer section at the bottom of the quiz file.

## Key Concepts Reviewed

### Variadic Templates
- `template <typename... Args>` - Parameter pack declaration
- `Args... args` - Function parameter pack
- `args...` - Parameter pack expansion
- Recursive template instantiation patterns

### Folding Expressions (C++17)
- `(args + ...)` - Unary right fold
- `(... + args)` - Unary left fold  
- `(args + ... + 0)` - Binary fold with init value
- `(f(args), ...)` - Comma operator folding

### Perfect Forwarding
- `Args&& args` - Universal reference
- `std::forward<Args>(args)...` - Perfect forwarding expansion
- Preserving lvalue/rvalue categories

### Advanced Patterns
- SFINAE with variadic templates
- Type traits with parameter packs
- Variadic class templates
- Recursive inheritance patterns

## Requirements Met
- ✅ Over 50 blank lines/holes to fill
- ✅ Based on existing test_variadic_*.cpp files
- ✅ Includes comprehensive answer section
- ✅ Has test functions for validation
- ✅ Covers key variadic template specifications

## Compilation Requirements
- C++17 compatible compiler (for folding expressions)
- Standard library support for type_traits, utility, algorithm

Enjoy practicing variadic templates! 🚀