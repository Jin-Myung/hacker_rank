#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int partition(vector <int> &ar, int lo, int hi) {
    int pivot = ar[hi];
    int curr = lo;
    int greater = lo;
    while (1) {
        if (ar[curr] < pivot) {
            swap(ar[curr], ar[greater]);
            ++curr;
            ++greater;
        } else {
            ++curr;
        }
        if (curr >= hi) {
            break;
        }
    }
    swap(ar[hi], ar[greater]);
    return greater;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<int> arr;
    for (int ii = 0; ii < n; ++ii) {
        int num;
        cin >> num;
        arr.push_back(num);
    }
    int med = n/2;
    int lo = 0;
    int hi = arr.size()-1;
    while (1) {
        int pos = partition(arr, lo, hi);
        if (pos == med) {
            cout << arr[pos] << endl;
            break;
        } else if (pos < med) {
            lo = pos+1;
        } else {
            hi = pos-1;
        }
    }
    return 0;
}
