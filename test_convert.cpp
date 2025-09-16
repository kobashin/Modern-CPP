#include <iostream>
#include <string>

std::string convert(int* arrayInput) {
    std::string stringOutput = "";
    int i;

    for (i = 0; i < 5; i++) {
        if (arrayInput[i] == 1) {
            stringOutput.push_back('A');
        }
        else {
            stringOutput.push_back('B');
        }
    }
    return stringOutput;
}

int main(void) {
    int arr_1[5] = {0, 0, 1, 2, 1};
    int arr_2[5] = {0, 1, 2, 1, 1};
    int arr_3[5] = {1, 0, 1, 2, 0};
    int arr_4[5] = {1, 1, 2, 1, 0};

    std::cout << convert(arr_1) << std::endl;
    std::cout << convert(arr_2) << std::endl;
    std::cout << convert(arr_3) << std::endl;
    std::cout << convert(arr_4) << std::endl;

    return 0;
}