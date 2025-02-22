// 与えられた2個の自然数の最小公倍数を計算する
#include <vector>
#include <cmath>
#include "math_funcs.h"

int main() {
    
    // 最小公倍数は24

    /*
        まず素因数分解をする
        12 = 2^2 * 3^1
        8  = 2^3 * 3^0

        全ての基数(2, 3)についてその指数部が最大の値を決める
        2 -> 3
        3 -> 1

        最後に基数を最大指数を組み合わせて最小公倍数を計算する
        2^3 * 3^1 = 24
    */

    int a = 36;
    int b = 48;

    vector<int> factors_a = {};
    vector<int> factors_b = {};

    primeFactorize(a, factors_a);
    primeFactorize(b, factors_b);

    // ckeck output
    cout << "All factors in a : ";
    print(factors_a);

    cout << "All factors in b : ";
    print(factors_b);

    /*
        factors_a, factors_bの間でuniqueな値を見つける
        a : 2, 3
        b : 2
        => uniqueな値は2, 3

        uniqueな基数それぞれについて、指数(index)の最大値を調べる
            factors_aにないならば、index_a = 0
            factors_aにあれば、index_a = <同じ基数の個数>
        factors_bに対しても同様の処理を行い、index_aとindex_bの大きい方を採用する

        結果、index_2 = 3, index_3 = 1となるので、
        最小公倍数は2^3 * 3^1 = 24となる
    */
    
    // backup prime factorized values to count bases
    vector<int> factors_a_org = factors_a;
    vector<int> factors_b_org = factors_b;

    erase_duplicate(factors_a);
    cout << "Unique values of factors_a : ";
    print(factors_a);

    erase_duplicate(factors_b);
    cout << "Unique values of factors_b : ";
    print(factors_b);

    vector<int> merged_factors = factors_a;
    for (int factor : factors_b) {
        merged_factors.push_back(factor);
    }

    // the input of unique() must be sorted.
    // remove duplicated values : pocket reference p426
    // sort vector : pocket reference p410
    sort(merged_factors.begin(), merged_factors.end());

    erase_duplicate(merged_factors);
    
    cout << "Unique values in merged_factors : ";
    print(merged_factors);

    // count index in each veector
    // count/count_if : pocket reference p412
    vector<int> num_of_index(merged_factors.size(), 0);
    for (int i = 0; i < merged_factors.size(); i++) {
        int tmp_index = merged_factors[i];
        int count_a = count(factors_a_org.cbegin(), factors_a_org.cend(), tmp_index);
        int count_b = count(factors_b_org.cbegin(), factors_b_org.cend(), tmp_index);
        // cout << "count_a : " << count_a << " / count_b : " << count_b << endl;
        num_of_index[i] = (count_a < count_b ? count_b : count_a);
    } 

    int least_common_multiple = 1;
    cout << "num_of_index : " << endl;
    for (int i = 0; i < merged_factors.size(); i++) {
        cout << "Base : " << merged_factors[i] <<
                " -> Max index : " << num_of_index[i] << endl;
        least_common_multiple *= pow(merged_factors[i], num_of_index[i]);
    }

    // the result is 144
    cout << "The least common multiple is " << least_common_multiple << "." << endl;

    return 0;
}
