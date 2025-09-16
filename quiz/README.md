# Lambda Quiz

This directory contains a comprehensive quiz to review lambda expressions in Modern C++.

## Files

- **lambda_quiz.cpp** - The main quiz file with blanks to fill in
- **lambda_quiz_answers.cpp** - Complete solutions and answers
- **README.md** - This instruction file

## Instructions

1. **Start with the quiz**: Open `lambda_quiz.cpp` and fill in all the blanks marked with `______`
2. **Cover all topics**: The quiz covers 15 sections with different lambda concepts:
   - Basic lambda syntax
   - Capture mechanisms (by value, by reference, mixed)
   - Return types and auto deduction
   - Mutable lambdas
   - Generic lambdas
   - Lambdas with STL algorithms
   - Nested lambdas
   - Function objects and recursive lambdas
   - Complex lambda expressions

3. **Test your work**: Compile and run your completed quiz to check if all tests pass:
   ```bash
   g++ -std=c++17 -o lambda_quiz lambda_quiz.cpp
   ./lambda_quiz
   ```

4. **Check answers**: Compare your solutions with `lambda_quiz_answers.cpp`

## Requirements Met

✅ **More than 50 blanks**: The quiz contains 60+ individual blanks covering various lambda concepts
✅ **Based on test code**: Extended and enhanced from the original `test_lambda.cpp`
✅ **Answer section**: Complete answer key provided in separate file and at bottom of quiz
✅ **Test functions**: Built-in assertions to validate correct completion
✅ **Key language specifications**: Covers all major lambda features in Modern C++

## Topics Covered

1. **Basic Syntax**: Lambda declaration, parameter lists, return types
2. **Capture Clauses**: 
   - `[=]` - Capture by value
   - `[&]` - Capture by reference  
   - `[=, &var]` - Mixed capture
   - `[var]` - Specific variable capture
3. **Advanced Features**:
   - `mutable` keyword
   - Generic lambdas with `auto`
   - Recursive lambdas with `std::function`
   - Lambda expressions in algorithms
4. **Practical Applications**:
   - STL algorithm usage
   - Sorting and searching
   - Functional programming patterns

## Expected Output

When completed correctly, the quiz should output expected values for each test case and conclude with:
```
All tests passed! Quiz completed successfully!
```

## Learning Objectives

After completing this quiz, you should understand:
- How to write lambda expressions with proper syntax
- Different capture mechanisms and when to use them
- How lambdas integrate with STL algorithms
- Advanced lambda features like mutability and recursion
- Best practices for lambda usage in Modern C++