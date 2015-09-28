#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int get_num_ana_pair(const string &str) {
    map<string, int> map_ana_cnt;
    for (int ii = 1; ii < str.length(); ++ii) {
        for (int jj = 0; jj <= str.length()-ii; ++jj) {
            string substr = str.substr(jj, ii);
            sort(substr.begin(), substr.end());
//            cout << substr << endl;
            map_ana_cnt[substr]++;
        }
    }
    int ret = 0;
    for (map<string, int>::const_iterator it = map_ana_cnt.cbegin();
            it != map_ana_cnt.cend(); ++it) {
//        cout << it->first << ": " << it->second << endl;
        if (it->second > 1) {
            ret += it->second * (it->second-1) / 2;
        }
    }
    return ret;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        cout << get_num_ana_pair(str) << endl;
    }
    return 0;
}
