#include <iostream>
#include <numeric>
using namespace std;

unsigned int gcd1(unsigned int const a, unsigned int const b) {
    /*
        a = 36, b = 48
        gcd(48, 36) = gcd(36, 12) = gcd(12, 0) = 12
        gcd(36, 48) = gcd(48, 36) = gcd(36, 12) = gcd(12, 0) = 12
        
    */
    return b == 0 ? a : gcd(b, a % b);
}

unsigned int gcd2(unsigned int a, unsigned int b) {
    while (b != 0) {
        unsigned int r = a % b;
        a = b;
        b = r;
    }

    return a;
}

int main() {
    cout << "Inputs numbers : ";
    unsigned int a, b;
    cin >> a >> b;

    cout
        << "    gcd1(" << a << ", " << b << ") = "
        << gcd1(a, b) << endl;

    cout
        << "    gcd2(" << a << ", " << b << ") = "
        << gcd2(a, b) << endl;

    cout
        << "    gcd(" << a << ", " << b << ") = "
        << gcd(a, b) << endl;

    return 0;
}