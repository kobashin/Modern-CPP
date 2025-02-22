/*
    16進数表記の文字列を入力し、それに対応する8bit整数の数列を返す関数

    "BAADF00D" or "baadf00d" -> {0xBA, 0xAD, 0xF0, 0x0D}
    "010203040506" -> {1, 2, 3, 4, 5, 6}
*/

#include <string>
#include <vector>
#include <iostream>
// #include <format>
#include <sstream>
#include <iomanip>
using namespace std;

void print(string hexstr) {
    

    for (int i = 0; 2*i < hexstr.size(); i++) {
        string subString = hexstr.substr(i, 2);
        int value;

        /*
            The line below creates an instance of std::stringstream,
            which is a stream class to operate on strings.
            It allows you to perform input and output operations on strings
            as if they were streams.
        */
        stringstream ss;

        /*
            "ss << hex"
            This sets the stream to interpret the following input as hexadecimal.
            The "hex" manipulator tells the stream to treat the input as a hexadecimal number.
        */
        ss << hex << subString;

        /*
            "ss >> value"
            This extracts the value from the stream ss and stores it in the integer variable value.
            The stream interprets the contents of subString as a hexadecimal number and converts it to an integer.
        */
        ss >> value;
        // cout << subString << " -> " << format("{:d}", subString) << endl;

        cout << subString << " -> " << value << endl;
    }
}

int main() {
    string s1 = "BAADF00D";
    string s2 = "baadf00d";
    string s3 = "010203040506";

    print(s1);
    print(s2);
    print(s3);

    return 0;
}