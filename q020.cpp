/*
    any, all, none function for container
*/

#include <vector>
#include <array>
#include <list>
#include <cassert>
using namespace std;

int main() {
    vector<int> v{1, 2, 3, 4, 5, 6};
    // assert(contains_any(v, 0, 3, 7));

    array<int, 6> a{{1, 2, 3, 4, 5, 6}};
    // assert(contains_all(a, 2, 5, 6));

    list<int> l{1, 2, 3, 4, 5, 6};
    // assert(!contains_none(l, 0, 9, 4));
}