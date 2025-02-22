/*
    8bit整数の配列またはベクトルを16進数表記の文字列に変換する

    {0xBA, 0xAD, 0xF0, 0x0D} -> "BAADF00D" or "baadf00d"
    {1, 2, 3, 4, 5, 6} -> "010203040506"
*/

#include <string>
#include <array>
#include <vector>
#include <iostream>
#include <format>
using namespace std;

template <class T>
void ucharToString(T elements) {
    for (auto bin : elements) cout << format("{:02X}", bin);
    cout << endl;
}

int main() {

    string a = to_string(100);
    cout << "int a = " << a << endl;

    string b = to_string(123.45);
    cout << "float b = " << b << endl;

    // test string format(C++20)
    cout << format("Hello {0} World!", "C++") << endl;
    cout << format("{:08b}", 13) << endl;
    cout << format("{:08x}", 13) << endl;
    cout << format("{:08X}", 13) << endl;
    cout << format("{:08o}", 13) << endl;
    cout << format("{0:.7}", 3.14159265358979L) << endl;
    cout << format("{0:+} {1:+04d}", 123, -456) << endl;
    cout << format("{0: } {1:+04d}", 123, -456) << endl;

    // 8bitであれば何でも良いはず
    // 10進表記
    cout << "decimal" << endl;
    cout << format("{:02x}", 186);
    cout << format("{:02X}", 186);
    cout << format("{:02x}", 173);
    cout << format("{:02X}", 173);
    cout << format("{:02x}", 240);
    cout << format("{:02X}", 240);
    cout << format("{:02x}", 13);
    cout << format("{:02X}", 13);
    cout << endl;

    // 16進表記
    cout << "hexadecimal" << endl;
    cout << format("{:02x}", 0xBA);
    cout << format("{:02X}", 0xBA);
    cout << format("{:02x}", 0xAD);
    cout << format("{:02X}", 0xAD);
    cout << format("{:02x}", 0xF0);
    cout << format("{:02X}", 0xF0);
    cout << format("{:02x}", 0x0D);
    cout << format("{:02X}", 0x0D);
    cout << endl;

    // 16進表記 -> 10進表記
    cout << "hexadecimal -> decimal" << endl;
    cout << format("0xBA = {:02d}", 0xBA) << endl;
    cout << format("0xAD = {:02d}", 0xAD) << endl;
    cout << format("0xF0 = {:02d}", 0xF0) << endl;
    cout << format("0x0D = {:02d}", 0x0D) << endl;
    cout << endl;

    // 16進表記 -> 2進表記
    cout << "hexadecimal -> decimal" << endl;
    cout << format("0xBA = {:08b}", 0xBA) << endl;
    cout << format("0xAD = {:02b}", 0xAD) << endl;
    cout << format("0xF0 = {:02b}", 0xF0) << endl;
    cout << format("0x0D = {:02b}", 0x0D) << endl;
    cout << endl;

    // 8bit整数の配列から16進表記の文字列に変換する
    unsigned char array_8bit_hexadecimal[4] = {0xBA, 0xAD, 0xF0, 0x0D};
    unsigned char array_8bit_decimal[6] = {1, 2, 3, 4, 5, 6};
    unsigned char array_8bit_binary[6] = 
        {0b00000001, 0b00000010, 0b00000011, 0b00000100, 0b00000101, 0b00000110};

    // 8bit整数のcpp配列から16進表記の文字列に変換する
    array<unsigned char, 4> cpp_array_8bit_hexadecimal = {0xBA, 0xAD, 0xF0, 0x0D};
    array<unsigned char, 4> cpp_array_8bit_decimal = {186, 173, 240, 13};
    array<unsigned char, 4> cpp_array_8bit_binary = 
        {0b10111010, 0b10101101, 0b11110000, 0b1101};

    // 8bit整数のベクトルから16進表記の文字列に変換する
    vector<unsigned char> vector_8bit_hexadecimal = {0xBA, 0xAD, 0xF0, 0x0D};
    vector<unsigned char> vector_8bit_decimal = {1, 2, 3, 4, 5, 6};
    vector<unsigned char> vector_8bit_binary = 
        {0b10111010, 0b10101101, 0b11110000, 0b1101};

    ucharToString(array_8bit_hexadecimal);
    ucharToString(array_8bit_decimal);
    ucharToString(array_8bit_binary);
    ucharToString(cpp_array_8bit_hexadecimal);
    ucharToString(cpp_array_8bit_decimal);
    ucharToString(cpp_array_8bit_binary);
    ucharToString(vector_8bit_hexadecimal);
    ucharToString(vector_8bit_decimal);
    ucharToString(vector_8bit_binary);

    return 0;
}