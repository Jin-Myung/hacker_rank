#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N, K, Q;
    cin >> N >> K >> Q;
    deque<int> arr;
    for (int ii = 0; ii < N; ++ii) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    vector<int> idx;
    for (int ii = 0; ii < Q; ++ii) {
        int temp;
        cin >> temp;
        idx.push_back(temp);
    }
    K %= N;
    while (K--) {
        arr.push_front(arr.back());
        arr.pop_back();
    }
    for (int ii = 0; ii < Q; ++ii) {
        cout << arr[idx[ii]] << endl;
    }
    cout << endl;
    return 0;
}
