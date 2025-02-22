#include "math_funcs.h"

void primeFactorize(int& n, vector<int>& v) {
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            int divided = static_cast<int>(n / i);
            v.push_back(i);
            // cout << i << " is push_backed into v." << endl;
            // cout << "primeFactorize(" << divided << ", v) is called." << endl;
            primeFactorize(divided, v);
            // cout << "breaking... n = " << n << ", i = " << i << endl;
            break;
        }
    }
}

void erase_duplicate(vector<int>& v) {
    v.erase(unique(v.begin(), v.end()), v.end());
}

void print(vector<int>& v) {
    for (int element : v) {
        cout << element << ", ";
    }
    cout << endl;
}