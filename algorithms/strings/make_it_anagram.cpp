#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string a, b;
    cin >> a >> b;
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
    cout << answer << endl;
    return 0;
}
