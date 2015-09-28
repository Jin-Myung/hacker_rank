#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

string get_output(string a, string b) {
    string ret;
    while (1) {
        if (a.empty()) {
            ret += b;
            break;
        }
        if (b.empty()) {
            ret += a;
            break;
        }
        if (a[0] == b[0]) {
            if (a < b) {
                ret += a[0];
                a = a.substr(1);
            } else {
                ret += b[0];
                b = b.substr(1);
            }
        } else if (a[0] < b[0]) {
            ret += a[0];
            a = a.substr(1);
        } else {
            ret += b[0];
            b = b.substr(1);
        }
    }
    return ret;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    while (T--) {
        string a, b;
        cin >> a >> b;
        cout << get_output(a, b) << endl;
    }
}
