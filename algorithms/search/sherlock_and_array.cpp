#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool can_be_equally_split(const vector<int> &arr, long sum) {
    long left_sum = 0;
    long right_sum = sum;
    for (int ii = 0; ii < arr.size(); ++ii) {
        if (ii > 0) {
            left_sum += arr[ii-1];
        }
        right_sum -= arr[ii];
        if (left_sum == right_sum) {
            return true;
        }
    }
    return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> arr;
        long sum = 0;
        while (N--) {
            int a;
            cin >> a;
            arr.push_back(a);
            sum += a;
        }
        if (can_be_equally_split(arr, sum)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}

