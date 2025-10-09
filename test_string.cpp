/*
    reference : pocket reference chapter 4
*/

#include <string>
#include <iostream>
#include <utility>
using namespace std;

// p188 : create string object
void create_string_object() {

    cout << "=== create_string_object() ===" << endl;

    string a;
    string b = "sample";
    string c(10, 't');
    string d = b;
    string e0 = b;
    string e = move(e0);
    string f(b.begin(), b.end());

    cout << "string a;" << " // " << a << endl;
    cout << "string b = \"sample\";" << " // " << b << endl;
    cout << "string c(10, 't');" << " // " << c << endl;
    cout << "string d = b;" << " // " << d << endl;
    cout << "string e = move(e0);" << " // " << e << endl;
    cout << "string f(b.begin(), b.end());" << " // " << f << endl;
}

// p195 : compare string objects
void compare_string_object() {

    cout << "=== compare_string_object() ===" << endl;

    string a = "123";
    string b = "123";

    cout << "string a = \"123\";" << endl << "string b = \"123\";" << endl;
    cout << "a == b : " << (a == b) << endl;
    cout << "a != b : " << (a != b) << endl;
    cout << "a < b : " << (a < b) << endl;
    cout << "a <= b : " << (a <= b) << endl;
    cout << "a > b : " << (a > b) << endl;
    cout << "a >= b : " << (a >= b) << endl;
}

// p202 : manipulate strings by using iterator
void foo(string::const_iterator a) {
    // do nothing
}

void foo(string::iterator a) {
    *a = 'x';
}

void manipulate_string_object() {

    cout << "=== manipulate_string_object() ===" << endl;

    // scan strings bu using range-for
    string x = "hello";
    cout << "x:";
    for (const char& c : x) {
        cout << c;
    }
    cout << endl;

    cout << "string y(x.rbegin(), x.rend());" << endl;
    string y(x.rbegin(), x.rend());
    cout << "y:" << y << endl;

    cout << "foo(y.cbegin());" << endl;
    foo(y.cbegin());
    cout << "y:" << y << endl;

    cout << "foo(y.begin());" << endl;
    foo(y.begin());
    cout << "y:" << y << endl;
}

int main() {
    create_string_object();
    compare_string_object();
    manipulate_string_object();

    return 0;
}