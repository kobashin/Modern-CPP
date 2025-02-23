#include <array>
#include <vector>
#include <iostream>
using namespace std;

void output(vector<int>& v) {
    cout << '{';
    for (int x : v) {cout << x << ' ';}
    cout << '}' << endl;
}

void push_back_all(const vector<int>& v, int a) {
    v.push_back(a);
}

int main() {
    vector<int> v = {1, 3, 7};
    output(v);
}