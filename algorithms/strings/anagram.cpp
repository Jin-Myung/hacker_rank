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
        string str;
        cin >> str;
        if (str.length() & 1) {
            cout << -1 << endl;
            continue;
        }
        string a = str.substr(0, str.length()/2);
        string b = str.substr(str.length()/2);
        vector<int> num('z'-'a'+1, 0);
        for (const auto &ch : a) {
            num[ch-'a']++;
        }
        for (const auto &ch : b) {
            num[ch-'a']--;
        }
        int answer = 0;
        for (const int &n : num) {
            answer += abs(n);
        }
        cout << answer/2 << endl;
    }
    return 0;
}
