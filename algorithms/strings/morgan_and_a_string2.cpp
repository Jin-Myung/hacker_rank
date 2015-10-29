#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

string get_output(const string &a, const string &b) {
    string ret;
    size_t pos_a = 0, pos_b = 0;
//static int ii = 0;
    while (1) {
        if (pos_a == a.size()) {
            ret += b.substr(pos_b);
            break;
        }
        if (pos_b == b.size()) {
            ret += a.substr(pos_a);
            break;
        }
        if (a[pos_a] == b[pos_b]) {
            if (a.substr(pos_a+1) < b.substr(pos_b+1)) {
                ret += a[pos_a];
                ++pos_a;
            } else {
                ret += b[pos_b];
                ++pos_b;
            }
        } else if (a[pos_a] < b[pos_b]) {
            ret += a[pos_a];
            ++pos_a;
        } else {
            ret += b[pos_b];
            ++pos_b;
        }
//if (ii++ < 100)
//cout << pos_a << " " << pos_b << ": " << ret << endl;
    }
//if (ii++ < 100)
//cout << pos_a << " " << pos_b << ": " << ret << endl;
    return ret;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    while (T--) {
        string a, b;
        cin >> a >> b;
        string out = get_output(a, b);
        cout << a.size() << " " << b.size() << " " << out.size() << endl;
        cout << out << endl;
    }
}
