#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

bool pangram(const string &str) {
    vector<int> ch_map('z'-'a'+1, 0);
//    cout << str << endl;
    for (const auto &ch : str) {
//        cout << ch << endl;
        if (ch >= 'a' && ch <= 'z') {
//            cout << "set lower" << endl;
            ch_map[ch-'a'] = 1;
        } else if (ch >= 'A' && ch <= 'Z') {
//            cout << "set upper" << endl;
            ch_map[ch-'A'] = 1;
        }
    }
    for (const auto &flag : ch_map) {
        if (0 == flag) {
            return false;
        }
    }
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string str;
    getline(cin, str);
    if (pangram(str)) {
        cout << "pangram" << endl;
    } else {
        cout << "not pangram" << endl;
    }
    return 0;
}
