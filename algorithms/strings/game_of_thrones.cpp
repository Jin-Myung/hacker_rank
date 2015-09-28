#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string str;
    cin >> str;
    vector<int> map_ch('z'-'a'+1, 0);
    for (const auto &ch : str) {
        map_ch[ch-'a']++;
    }
    bool odd_found = false;
    for (const auto &num : map_ch) {
        if (num & 1) {
            if (odd_found) {
                cout << "NO" << endl;
                return 0;
            } else {
                odd_found = true;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}
