# Modern C++ Regex Quiz

This folder contains a comprehensive quiz to review regular expressions (regex) and iterator concepts in Modern C++.

## Files

- **`regex_quiz.cpp`** - The main quiz file with 50+ blank sections to fill in
- **`regex_quiz_answers.cpp`** - The complete solution for reference and validation
- **`README.md`** - This documentation file

## How to Use

### Step 1: Study the Quiz
Open `regex_quiz.cpp` and read through the code. You'll find blanks marked with `_______` that need to be filled in.

### Step 2: Fill in the Blanks
Complete the missing parts by understanding:
- Regular expression patterns
- Iterator usage and concepts
- Template function implementation
- `std::regex_match` and `std::sregex_iterator` usage

### Step 3: Compile and Test
```bash
g++ -std=c++14 -o regex_quiz regex_quiz.cpp
./regex_quiz
```

### Step 4: Validate Your Solution
The quiz includes built-in test functions that will automatically validate your answers. If all tests pass, you've successfully completed the quiz!

### Step 5: Compare with Answers
If you get stuck, check `regex_quiz_answers.cpp` for the complete solutions.

## Key Concepts Covered

### Regex Concepts
- **Raw String Literals**: Using `R"(pattern)"` syntax
- **Pattern Matching**: Creating patterns for validation
- **Capture Groups**: Using parentheses to capture parts of matches
- **Character Classes**: `[A-Z]`, `\d`, `\w` patterns
- **Quantifiers**: `{3}`, `{3,4}`, `+` for repetition

### Iterator Concepts
- **Generic Programming**: Template functions with iterators
- **Iterator Operations**: `*`, `++`, `!=`, `begin()`, `end()`
- **Pointer Arithmetic**: Using pointers as iterators
- **Range-based Operations**: `next()` function usage

### Regex Library Functions
- **`std::regex`**: Creating regex pattern objects
- **`std::regex_match`**: Full string validation
- **`std::sregex_iterator`**: Finding multiple matches in text
- **Match Objects**: Using `.position()`, `.length()`, `.str()` methods

## Quiz Statistics

- **Total Lines**: 200+ lines of code
- **Blank Sections**: 50+ blanks to fill
- **Test Functions**: 8 different test scenarios
- **Validation Tests**: Automated assertions for correctness
- **Concepts**: Regex patterns, iterators, templates, STL algorithms

## Examples from Original Code

This quiz is based on:
- `test_regex_iterator.cpp` - Basic regex iterator usage
- `q029.cpp` - License plate validation and extraction

## Tips

1. Start with the simpler iterator concepts before moving to regex
2. Use the test output to understand what each function should do
3. Refer to the comments for hints about what each blank should contain
4. The answer section at the bottom provides line-by-line solutions
5. Don't modify the test functions - they validate your implementation

## Learning Outcomes

After completing this quiz, you will understand:
- How to create and use regular expressions in C++
- Iterator concepts and generic programming
- Template function implementation
- STL algorithms and their usage patterns
- Practical applications of regex for text processing

Happy learning! 🚀