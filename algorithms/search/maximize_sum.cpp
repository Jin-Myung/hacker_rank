#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <deque>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        int sum = 0;
        deque<int> arr;
        set<int> mod;
        while (N--) {
            int a;
            cin >> a;
            sum += a;
            mod.insert(sum % M);
            arr.push_back(a);
        }
        vector<int> mod_vec;
        for (auto it = mod.begin(); it != mod.end(); ++it) {
            mod_vec.push_back(*it);
        }
        int max = mod_vec[mod_vec.size()-1];
        for ()
        cout << endl;
    }
    return 0;
}
