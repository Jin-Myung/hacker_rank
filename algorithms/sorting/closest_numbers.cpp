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
    sort(arr.begin(), arr.end());
    int min_dist = arr[arr.size()-1] - arr[0];
    vector<int> ans;
    for (int ii = 0; ii < arr.size()-1; ++ii) {
        if (arr[ii+1] - arr[ii] <= min_dist) {
            if (arr[ii+1] - arr[ii] < min_dist) {
                ans.clear();
                min_dist = arr[ii+1] - arr[ii];
            }
            ans.push_back(arr[ii]);
            ans.push_back(arr[ii+1]);
        }
    }
    for (const int &ii : ans) {
        cout << ii << " ";
    }
    cout << endl;
    return 0;
}
