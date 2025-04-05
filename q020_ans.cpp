#include <vector>
#include <array>
#include <list>
#include <algorithm>
#include <cassert>
using namespace std;

template<class C, class T>
// general helper function
bool contains(C const& c, T const& value) {
    return std::cend(c) !=
    std::find(std::cbegin(c), std::cend(c), value);
}

template <class C, class... T>
bool contains_any(C const& c, T &&... value) {
    return (... || contains(c, value));
}

template <class C, class... T>
bool contains_all(C const& c, T &&... value) {
    return (... && contains(c, value));
}

template <class C, class... T>
bool contains_none(C const& c, T &&... value) {
    return !contains_any(c, std::forward<T>(value)...);
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