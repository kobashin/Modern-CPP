#include <iostream>

void print(int arr[4]) {
    for (int i = 0; i < 3; i++) {
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[3] << std::endl;
}

void swap(int arr[4], int m, int n) {
    int tmp = arr[m];
    arr[m] = arr[n];
    arr[n] = tmp;
}

void printArray() {
    int m, n, tmp;
    // int integerArray[4] = {2, 4, 1, 3};
    int integerArray[4] = {4, 3, 2, 1};

    for (n = 0; n < 3; n++) {
        for (m = 0; m < (3 - n); m++) {
            if (integerArray[m] > integerArray[m + 1]) {
                swap(integerArray, m, m + 1);
            }
        }
        print(integerArray);
    }
    print(integerArray);
}

int main(void) {
    printArray();
    return 0;
}