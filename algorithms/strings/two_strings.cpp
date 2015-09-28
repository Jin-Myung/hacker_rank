#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    while (T--) {
        string a, b;
        cin >> a >> b;
        vector<int> num('z'-'a'+1, 0);
        for (const auto &ch : a) {
            num[ch-'a']++;
        }
        bool found = false;
        for (const auto &ch : b) {
            if (num[ch-'a']) {
                found = true;
                break;
            }
        }
        if (found) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
