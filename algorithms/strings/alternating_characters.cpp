#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int get_num_del(const string &str) {
    int ret = 0;
    char curr_ch = str[0];
    for (string::size_type ii = 1; ii < str.size(); ii++) {
        if (str[ii] == curr_ch) {
            ret++;
        } else {
            curr_ch = str[ii];
        }
    }
    return ret;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    while(T--) {
        string str;
        cin >> str;
        cout << get_num_del(str) << endl;
    }
    return 0;
}
