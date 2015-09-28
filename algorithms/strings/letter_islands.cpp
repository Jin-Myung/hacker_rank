#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int get_num_is(
        const string &str,
        const string &substr
        ) {
    decltype(str.length()) nn = str.length(), ss = substr.length();
    vector<int> marker(nn, 0);
    decltype(nn) ii, jj;
    for (ii = 0; ii <= nn-ss; ++ii) {
        if (str.substr(ii, ss) == substr) {
            for (jj = ii; jj < ii + ss; ++jj) {
                marker[jj] = 1;
            }
        }
    }
    int ret = 0;
    for (decltype(marker.size()) kk = 1; kk < marker.size(); ++kk) {
        if (marker[kk-1] == 1 && marker[kk] == 0) {
            ret++;
        }
    }
    if (marker[marker.size()-1] == 1)
        ret++;
    return ret;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string str;
    int num_target_is;
    cin >> str >> num_target_is;
    set<string> suit_substrs;
    decltype(str.length()) ii, jj, nn = str.length();
    for (ii = 0; ii <= nn-1; ++ii) {
        for (jj = ii+1; jj <= nn; ++jj) {
            if (1.*nn/(jj-ii) < 1.*num_target_is) {
                break;
            }
            string substr = str.substr(ii, jj-ii);
            if (suit_substrs.find(substr) != suit_substrs.end()) {
                continue;
            }
            if (num_target_is == get_num_is(str, substr)) {
                suit_substrs.insert(substr);
            }
        }
    }
    cout << suit_substrs.size() << endl;
    return 0;
}
