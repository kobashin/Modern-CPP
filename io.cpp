#include <iostream>
#include <string>

int main() {
    // p228
    std::clog << "This is an error." << std::endl;
    std::cerr << "This is also an error." << std::endl;

    // p231
    std::string s = "Irowa nioedo chirinuru wo";
    char c = 'A';
    int i = 10;
    double d = 20.25;
    long double ld = 6.62606957e-34;
    void* p = &c;

    std::cout << 'A';
    std::cout << "Text\n";
    std::cout << s << '\n' << std::flush;
    std::cout << 0 << ' ' << i << '\n';
    std::cout << d << ' ' << ld << '\n';
    std::cout << p << std::endl;
    std::cout << true << std::endl;

    return 0;
}