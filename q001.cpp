// 1. 与えられた上限までの3または5で割り切れる正の整数の総和を計算して出力するプログラム

#include <iostream>
using namespace std;

int main () {
    long long int upperLimit = 10;
    long long int sum = 0;

    for (long long int i = 0; i <= upperLimit; i++) {
        if ((i % 3 == 0) || (i % 5 == 0)) {
            sum += i;
        }
    }

    cout << "sum : " << sum << endl;
    return 0;
}
