/*
    https://cpprefjp.github.io/lang/cpp11/scoped_enum.html
*/
#include <iostream>
#include <type_traits>
#include <cassert>

int main() {
    // scoped enumalation type with base-type
    enum class Color : int {Red, Green, Blue};

    Color c = Color::Blue;
    // int color = static_cast<int>(Color::Blue);  // OK
    int color = static_cast<std::underlying_type<Color>::type>(Color::Blue);
    // int color = Color::Blue; // error: implicit conversion
    color = 2;
    assert(color == 2);
    std::cout << "color : " << color << std::endl;

    return 0;
}

/*
    In Modern C++ (C++11 and later), templates can accept various types of parameters beyond just `typename` or `class`. Here are the main categories of template parameters:

### 1. **Type Parameters**
   - `typename` or `class`: These are interchangeable and represent a type.
     ```cpp
     template <typename T>
     class MyClass {};
     ```

### 2. **Non-Type Parameters**
   Templates can accept non-type parameters, which are constant values known at compile time. Examples include:
   - **Integral values** (e.g., `int`, `char`, `bool`, etc.):
     ```cpp
     template <int N>
     class Array {};
     ```
   - **Pointers**:
     ```cpp
     template <int* Ptr>
     class MyClass {};
     ```
   - **References**:
     ```cpp
     template <int& Ref>
     class MyClass {};
     ```
   - **Enumerators**:
     ```cpp
     enum class Color { Red, Green, Blue };
     template <Color C>
     class MyClass {};
     ```
   - **std::nullptr_t**:
     ```cpp
     template <std::nullptr_t N>
     class MyClass {};
     ```

### 3. **Template Template Parameters**
   Templates can accept other templates as parameters.
   ```cpp
   template <template <typename> class Container>
   class MyClass {};
   ```

### 4. **Auto (C++17)**
   You can use `auto` as a template parameter to deduce the type automatically.
   ```cpp
   template <auto N>
   class MyClass {};
   ```

### 5. **Concepts (C++20)**
   You can use concepts to constrain template parameters.
   ```cpp
   template <typename T>
   concept Addable = requires(T a, T b) { a + b; };

   template <Addable T>
   T add(T a, T b) {
       return a + b;
   }
   ```

### 6. **Variadic Templates**
   Templates can accept a variable number of parameters.
   ```cpp
   template <typename... Args>
   class MyClass {};
   ```

### 7. **Default Template Arguments**
   Templates can have default arguments for type or non-type parameters.
   ```cpp
   template <typename T = int, int N = 10>
   class MyClass {};
   ```

These features make Modern C++ templates highly flexible and powerful for generic programming.

*/