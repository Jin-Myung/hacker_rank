#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long get_perm(int n, int k) {
    if (k == 0) {
        return 1;
    }
    long ret = n;
    for (int ii = 1; ii < k; ++ii) {
        ret *= (n-ii);
    }
    return ret;
}

long factor(int k) {
    if (k <= 1) {
        return 1;
    }
    return k * factor(k-1);
}

int get_binomial_parity(int n, int k) {
    if (n-k < k) {
        k = n-k;
    }
    if (k < 10) {
        long comb = get_perm(n, k) / factor(k);
        if (comb % 2 == 0) {
            return 0;
        } else {
            return 1;
        }
    }
    if (n % 2 == 0 && k % 2 == 1) {
        // even
        return 0;
    } else {
        return get_binomial_parity(n/2, k/2);
    }
}

void sxor() {
    int N;
    cin >> N;
    vector<int> arr;
    while (N--) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    int res = 0;
    for (int ii = 0; ii < arr.size(); ++ii) {
        int num_rep = get_binomial_parity(arr.size()-1, ii) + arr.size() - 1;
        cout << num_rep << " ";
        if (num_rep % 2) {
            res ^= arr[ii];
        }
    }
    cout << endl;
    cout << res << endl;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    while (T--) {
        sxor();
    }
    return 0;
}
