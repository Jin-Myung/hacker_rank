#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <assert.h>

using namespace std;

int bin_search(const vector<int> &arr, int value, int lo, int hi) {
    int mid = (hi-lo)/2+lo;
    if (arr[mid] == value) {
        while (arr[mid-1] == value) {
            --mid;
        }
        return mid;
    }
    if (arr[mid] > value && mid > 0 && arr[mid-1] < value) {
        return mid;
    }
    if (lo >= hi) {
        // lo == 0
        return mid;
    }
    if (arr[mid] > value) {
        hi = mid-1;
        return bin_search(arr, value, lo, hi);
    } else {
        lo = mid+1;
        return bin_search(arr, value, lo, hi);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;
    vector<int> arr;
    while (N--) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    int T;
    cin >> T;
    while (T--) {
        int input;
        cin >> input;
//        for (int ii = 0; ii < arr.size(); ++ii) {
//            if (input == arr[ii]) {
//                cout << "Yes " << ii+1 << endl;
//                break;
//            } else if (input < arr[ii]) {
//                cout << "No " << ii+1 << endl;
//                break;
//            }
//        }
        int idx = bin_search(arr, input, 0, arr.size()-1);
        if (arr[idx] == input) {
            cout << "Yes " << idx+1 << endl;
        } else {
            cout << "No " << idx+1 << endl;
        }
    }
    return 0;
}
