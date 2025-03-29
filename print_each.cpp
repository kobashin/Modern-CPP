#include <iostream>
using namespace std;

void print_star(int num) {
    int cnt = 0;
    char sc1 = '*';
    char sc2 = '-';
    char print_char = sc1;
    while (cnt < num)
    {
        if (print_char == sc1) {
            cout << sc1;
            print_char = sc2;
        }
        else {
            cout << sc2;
            print_char = sc1;
        }
        cnt += 1;
    }
    cout << endl;
}

int main() {
    print_star(20);
    return 0;
}