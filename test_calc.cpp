#include <iostream>
using namespace std;

void print(int x) {
    cout << x << endl;
}

int calcX(int inData) {
    int num, i;
    num = inData;

    print(num);

    for (i = 1; i <= 3; i++) {
        num = num + 2 * i;
        print(num);
    }

    return num;
}

int calcY(int inData) {
    int num, i;
    num = inData;

    print(num);

    for (i = 2; i <= 6; i=i+2) {
        num = num + 2 * i;
        print(num);
    }

    return num;
}

int main(void) {
    print(calcX(1));
    print(calcY(1));
}