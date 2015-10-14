#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Elem {
    int idx;
    int value;
public:
    Elem(int i, int &v) : idx(i), value(v) { }
    bool operator< (const Elem &rhs) {
        return value < rhs.value;
    }
};

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    while (T--) {
        int M, N;
        cin >> M >> N;
        vector<Elem> arr;
        long sum = 0;
        for (int ii = 0; ii < N; ++ii) {
            int a;
            cin >> a;
            arr.push_back(Elem(ii+1, a));
            sum += a;
        }
        sort(arr.begin(), arr.end());
        vector<Elem>::iterator lo = arr.begin();
        vector<Elem>::iterator hi = arr.end()-1;
        while (1) {
            if (hi <= lo) {
                break;
            }
            int sum = lo->value+hi->value;
            if (sum == M) {
                cout << min(lo->idx, hi->idx) << " " << max(lo->idx, hi->idx) << endl;
                break;
            } else if (sum < M) {
                lo++;
            } else {
                hi--;
            }
        }
    }
    return 0;
}

