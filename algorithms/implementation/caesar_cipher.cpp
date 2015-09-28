#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, k;
    string str;
    cin >> n >> str >> k;
    k %= 26;
    for (auto &ch : str) {
        if (isalpha(ch)) {
            if (islower(ch)) {
//                cout << static_cast<int>(ch) << endl;
                ch += k;
                if (ch < 0) {
                    ch += 128;
                }
//                cout << static_cast<int>(ch) << endl;
                if (ch < 'a' || ch > 'z') {
                    ch = ch - 'z' + 'a' - 1;
                    if (ch < 0) {
                        ch += 128;
                    }
//                cout << static_cast<int>(ch) << endl;
                }
            } else {
                ch += k;
                if (ch < 0) {
                    ch += 128;
                }
                if (ch < 'A' || ch > 'Z') {
                    ch = ch - 'Z' + 'A' - 1;
                    if (ch < 0) {
                        ch += 128;
                    }
                }
            }
        }
    }
    cout << str << endl;
    return 0;
}
