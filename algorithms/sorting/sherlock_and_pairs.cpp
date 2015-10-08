#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> arr;
        while (N--) {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }
        sort(arr.begin(), arr.end());
//        for (int ii = 0; ii < arr.size(); ++ii) {
//            cout << arr[ii] << " ";
//        }
//        cout << endl;
        long same_cnt = 1;
        long long ans = 0;
        for (int ii = 1; ii < arr.size(); ++ii) {
            if (arr[ii] == arr[ii-1]) {
                ++same_cnt;
            } else {
                if (same_cnt > 1) {
//                    cout << "  " << same_cnt << endl;
                    ans += same_cnt * (same_cnt-1);
                }
                same_cnt = 1;
            }
        }
        if (same_cnt > 1) {
//            cout << "  " << same_cnt << endl;
            ans += same_cnt * (same_cnt-1);
        }
        cout << ans << endl;
    }
    return 0;
}
