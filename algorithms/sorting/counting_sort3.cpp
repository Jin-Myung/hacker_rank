#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> arr;
    while (n--) {
        int num;
        string str;
        cin >> num >> str;
        arr.push_back(num);
    }
    vector<int> cnt(100, 0);
    for (const int &num : arr) {
        cnt[num]++;
    }
    int sum = 0;
    for (const int &ii : cnt) {
        sum += ii;
        cout << sum << " ";
    }
    cout << endl;
    return 0;
}
