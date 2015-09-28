#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int update_exist(
        vector<int> &exist,
        const vector<int> &str_exist
        ) {
    for (decltype(exist.size()) ii = 0; ii < exist.size(); ++ii) {
        if (exist[ii] && str_exist[ii]) {
            exist[ii] = 1;
        } else {
            exist[ii] = 0;
        }
    }
    return 0;
}

int count_exist(const vector<int> &exist) {
    int ret = 0;
    for (const auto &ex : exist) {
        if (ex) {
            ret++;
        }
    }
    return ret;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    vector<int> exist('z'-'a'+1, 1);
    for (int ii = 0; ii < N; ii++) {
        string str;
        cin >> str;
        vector<int> str_exist('z'-'a'+1, 0);
        for (const auto &ch : str) {
            str_exist[ch-'a'] = 1;
        }
/*        for (const auto &ex : str_exist) {
            cout << ex;
        }
        cout << endl;
*/        update_exist(exist, str_exist);
/*        for (const auto &ex : exist) {
            cout << ex;
        }
        cout << endl;
*/    }
    cout << count_exist(exist) << endl;
    return 0;
}
