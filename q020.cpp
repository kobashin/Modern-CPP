/*
    any, all, none function for container
*/

#include <vector>
#include <array>
#include <list>
#include <algorithm>
#include <cassert>
using namespace std;

template <typename Container>
bool contains(Container c, int a) {
    auto found = find(c.cbegin(), c.cend(), a);
    if (found != c.cend()) {
        return true;
    }
    else {
        return false;
    }
}

// contains_any
bool contains_any(vector<int> v, int a) {
    return contains(v, a);
}

template <typename... Types>
bool contains_any(vector<int> v, int t1, Types... args) {
    bool tmp_tf = contains(v, t1);
    return tmp_tf || contains_any(v, args...);
}

// contains_all
bool contains_all(array<int, 6> a, int x) {
    return contains(a, x);
}

template <typename... Types>
bool contains_all(array<int, 6> a, int t1, Types... args) {
    bool tmp_tf = contains(a, t1);
    return tmp_tf && contains_all(a, args...);
}

// contains_none
bool contains_none(list<int> l, int a) {
    return ~contains(l, a);
}

template <typename... Types>
bool contains_none(list<int> l, int t1, Types...args) {
    bool tmp_tf = ~contains(l, t1);
    return tmp_tf && contains_none(l, args...);
}

int main() {
    vector<int> v{1, 2, 3, 4, 5, 6};
    // success
    assert(contains_any(v, 0, 6, 7));
    // failed
    // assert(contains_any(v, 0, 9, 7));

    array<int, 6> a{{1, 2, 3, 4, 5, 6}};
    // success
    assert(contains_all(a, 2, 5, 6));
    // failed
    // assert(contains_all(a, 2, 6, 7));

    list<int> l{1, 2, 3, 4, 5, 6};
    // success
    assert(contains_none(l, 0, 8, 9));
    // failed
    // assert(!contains_none(l, 0, 9, 4));
}