#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n-1);
}

int get_binomial(int k, int n) {
    if (k == 0 || k == n) {
        return 1;
    }
    return factorial(n) / factorial(n-k) / factorial(k);
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
        int num_rep = get_binomial(ii, arr.size()-1) + arr.size() - 1;
//        cout << num_rep << " ";
        if (num_rep % 2) {
            res ^= arr[ii];
        }
    }
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
