// Find the most frequently used element in a elements.

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
struct mfu_type {
    std::vector<T> value = {};
    size_t used_times = 0;
    void print() {
        for (T x : value) {
            std::cout << "{" << x << "," << used_times << "}" << std::endl;
        }
    }
};

template <typename T>
mfu_type<T> get_most_frequently_used(std::vector<T> v) {

    std::vector<T> v_original = v;

    std::sort(v.begin(), v.end());
    
    // get unique values in argument vector: v_unique
    v.erase(std::unique(v.begin(), v.end()), 
            v.end());
    
    // for each element in v_unique, calc how many times it's used
    mfu_type<T> mfu;
    size_t count_tmp = 0;

    for (T x : v) {
        count_tmp = std::count(v_original.begin(), v_original.end(), x);
        if (count_tmp > mfu.used_times) {
            mfu.used_times = count_tmp;
            mfu.value.clear();
            mfu.value.push_back(x);
        }
        else if (count_tmp == mfu.used_times) {
            mfu.value.push_back(x);
        }
        else {
            // do nothing
        }
    }

    // return mfu value
    return mfu;
}

int main() {
    std::vector<int> v = {1,2,3,2,2,1,4,5,6,4,5,2,1,3,0,2};
    mfu_type<int> mfu_1 = get_most_frequently_used(v);
    std::cout << "Input vector: {";
    for (size_t n = 0; n < v.size(); n++) {
        std::cout << v[n] << (n == v.size() - 1 ? "" : ", ");
    }
    std::cout << "}" << std::endl;
    mfu_1.print();

    std::vector<float> f = {1.23, 3.14, 2.78, 0.333, 1.23, 3.14, 0.11, 3.14};
    mfu_type<float> mfu_2 = get_most_frequently_used(f);
    std::cout << "Input vector: {";
    for (size_t m = 0; m < f.size(); m++) {
        std::cout << f[m] << (m == f.size() - 1 ? "" : ", ");
    }
    std::cout << "}" << std::endl;
    mfu_2.print();
}
