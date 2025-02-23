#include <array>
#include <vector>
#include <iostream>
using namespace std;

template <class T>
void output(vector<T>& c) {
    cout << '{';
    for (T x : c) {cout << x << ' ';}
    cout << '}' << endl;
}

template <class T>
void push_back_all(vector<T>& v, T a) {
    v.push_back(a);
}

template <class T, class... Ts>
void push_back_all(vector<T>& v, T v1, Ts...tail){
    v.push_back(v1);
    push_back_all(v, tail...);
}

int main() {
    vector<double> f = {1.2, 1.51, 2.01, 0.01};
    vector<int> v = {1, 3, 7};
    output(f);
    output(v);

    push_back_all(f, 3.14, 2.78, 0.123);
    push_back_all(v, 4, 12, 0);
    output(f);
    output(v);
}