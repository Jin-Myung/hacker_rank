#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

const string::const_iterator &get_ch_to_be_removed(
        const string::const_iterator &b,
        const string::const_iterator &e
        ) {
    string::const_iterator bb = b;
    string::const_iterator ee = e;
    while (1) {
        if (ee <= bb) {
            break;
        }
        if (*bb != *(ee-1) && *(bb+1) == *ee) {
            return b;
        }
        if (*bb == *(ee-1) && *(bb+1) != *ee) {
            return e;
        }
        ++bb;
        --ee;
    }
    return b;
}

int get_pel_idx(const string &str) {
    string::const_iterator b = str.begin(), e = str.end()-1;
    while (1) {
        if (*b != *e) {
//            cout << *b << " " << *e << endl;
            return get_ch_to_be_removed(b, e) - str.begin();
        }
        if (e <= b) {
            break;
        }
        ++b;
        --e;
    }
    return -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        cout << get_pel_idx(str) << endl;
    }
    return 0;
}
