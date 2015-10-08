#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Elem_type {
    int num;
    string str;
    bool second_half = 0;
public:
    Elem_type(int _n, string &_s) : num(_n), str(_s) { }
    bool operator < (const Elem_type &rhs) const {
        return num < rhs.num;
    }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<Elem_type> arr;
    for (int ii = 0; ii < n; ++ii) {
        int num;
        string str;
        cin >> num >> str;
        Elem_type et(num, str);
        if (ii >= n/2) {
            et.second_half = true;
        }
        arr.push_back(et);
    }
    stable_sort(arr.begin(), arr.end());
    for (const Elem_type &e : arr) {
        if (e.second_half) {
            cout << e.str << " ";
        } else {
            cout << "- ";
        }
    }
    cout << endl;
    return 0;
}
