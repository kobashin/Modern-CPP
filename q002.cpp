// 与えられた2個の自然数の最大公約数を計算する
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include "math_funcs.h"

int main() {
    int a = 36;
    int b = 48;

    vector<int> factors_a = {};
    vector<int> factors_b = {};

    int greatest_common_divisor = 1;

    /*
        36 = 2^2 * 3*2
        48 = 2^4 * 3*1

        最小公倍数の場合、各基数の指数のうち最大値を取得すればよい
        最大公約数の場合、各基数の指数のうち最小値を取得すればよい
    */

    // 素因数分解
    primeFactorize(a, factors_a);
    primeFactorize(b, factors_b);

    // backup prime factorized values to count bases
    vector<int> factors_a_org = factors_a;
    vector<int> factors_b_org = factors_b;

    // test
    cout << "primeFactorize(a, factors_a) -> ";
    print(factors_a);
    cout << "primeFactorize(b, factors_b) -> ";
    print(factors_b);

    // uniqueな基数の抽出
    erase_duplicate(factors_a);
    erase_duplicate(factors_b);

    // test
    cout << "erase_duplicate(factors_a) -> ";
    print(factors_a);
    cout << "erase_duplicate(factors_b) -> ";
    print(factors_b);

    // uniqueな基数を連結した配列を作る
    vector<int> merged_factors = factors_a;
    for (int factor : factors_b) {
        merged_factors.push_back(factor);
    }

    // 連結した基数の配列から重複を削除する
    // これによって複数の自然数を構成する基数の中でuniqueなものを見つける
    sort(merged_factors.begin(), merged_factors.end());
    erase_duplicate(merged_factors);

    // test
    cout << "erase_duplicate(merged_factors) -> ";
    print(merged_factors);

    // count/count_if : pocket reference p412
    vector<int> num_of_index(merged_factors.size(), 0);
    for (int i = 0; i < merged_factors.size(); i++) {
        int tmp_index = merged_factors[i];
        int count_a = count(factors_a_org.cbegin(), factors_a_org.cend(), tmp_index);
        int count_b = count(factors_b_org.cbegin(), factors_b_org.cend(), tmp_index);
        // 最小公倍数の時はindexの小さい方を取ればよい
        num_of_index[i] = (count_a < count_b ? count_a : count_b);
    }

    // 最小公倍数の計算
    for (int i = 0; i < merged_factors.size(); i++) {
        cout << "Base : " << merged_factors[i] <<
                " -> Minimum index : " << num_of_index[i] << endl;
        greatest_common_divisor *= pow(merged_factors[i], num_of_index[i]);
    }

    // the result is 12
    cout << "The least common multiple is " << greatest_common_divisor << "." << endl;

    return 0;
}
