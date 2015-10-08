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
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    if (arr == sorted) {
        cout << "yes" << endl;
    } else {
        vector<int> idx_diff;
        for (int ii = 0; ii < arr.size(); ++ii) {
            if (arr[ii] != sorted[ii]) {
                idx_diff.push_back(ii);
            }
        }
        if (idx_diff.size() == 2) {
            cout << "yes" << endl;
            cout << "swap " << idx_diff[0]+1 << " " << idx_diff[1]+1 << endl;
        } else {
            bool reversed = true;
            for (int ii = idx_diff[0]; ii <= idx_diff[idx_diff.size()-1]; ++ii) {
                if (arr[ii] != sorted[idx_diff[idx_diff.size()-1]-ii+idx_diff[0]]) {
                    reversed = false;
                    break;
                }
            }
            if (reversed) {
                cout << "yes" << endl;
                cout << "reverse " << idx_diff[0]+1 << " " << idx_diff[idx_diff.size()-1]+1 << endl;
            } else {
                cout << "no" << endl;
            }
        }
    }
    return 0;
}
