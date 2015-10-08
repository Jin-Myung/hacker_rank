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
        cin >> num;
        arr.push_back(num);
    }
    vector<int> cnt(100, 0);
    for (const int &num : arr) {
        cnt[num]++;
    }
    for (int ii = 0; ii < cnt.size(); ++ii) {
        for (int jj = 0; jj < cnt[ii]; ++jj) {
            cout << ii << " ";
        }
    }
    cout << endl;
    return 0;
}

