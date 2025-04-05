/*
    Kelvin
    Celsius
    Fahrenheit

    K = C + 273.15
    F = 1.8C + 32

    300K
    It's 26.85degree's Celsius.
    It's 80.33Fahrenheit.
    It's 300Kelvin.

    ToDo
    - template_cast by using Traits
    - operator : == != < > <= >= += -= 
*/

#include <iostream>

long double operator"" _deg(long double d) {
    return d + 273.15L;
}

long double operator"" _f(long double f) {
    // return 1.8L * (K - 273.15) + 32;
    return (f - 32) / 1.8 + 273.15;
}

long double operator"" _K(long double K) {
    return K;
}

bool are_equal(long double const a1, long double const a2, long double eps = 0.000001) {
    return ((a1 - a2) < eps);
}

int main() {

    std::cout << "It's " << 26.85_deg << "degree's Celsius." << std::endl;
    std::cout << "It's " << 80.33_f << "Fahrenheit." << std::endl;
    std::cout << "It's " << 300.0_K << "Kelvin." << std::endl;

    std::cout << "are_equal(26.85deg, 80.33f) : "
              << are_equal(26.85_deg, 80.33_f) << std::endl;
    std::cout << 26.85_deg << std::endl << 80.33_f << std::endl
              << (26.85_deg - 80.33_f) << std::endl;

    return 0;
}