#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <algorithm>
#include <cassert>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6};
    array<int, 5> a = {3, 4, 6, 8, 9};
    list<int> l = {0, 2, 5, 6, 9};

    auto f = [](int x)-> bool {return x > 2;};

    for (int x : v) {
        cout << f(x) << endl;
    }

}