#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

void partition(vector <int> &ar, int lo, int hi) {
    int pivot = ar[lo];
    vector<int> part_less;
    vector<int> part_greater;
    for (int ii = lo+1; ii <= hi; ++ii) {
        if (ar[ii] < pivot) {
            part_less.push_back(ar[ii]);
        } else {
            part_greater.push_back(ar[ii]);
        }
    }
    vector<int> ar_left = vector<int>(ar.begin(), ar.begin()+lo);
    vector<int> ar_right = vector<int>(ar.begin()+hi+1, ar.end());
    ar = ar_left;
    ar.insert(ar.end(), part_less.begin(), part_less.end());
    ar.push_back(pivot);
    ar.insert(ar.end(), part_greater.begin(), part_greater.end());
    ar.insert(ar.end(), ar_right.begin(), ar_right.end());
    for (int ii = 0; ii < ar.size(); ++ii) {
        cout << ar[ii] << " ";
    }
    cout << endl;
}

int main(void) {
    vector <int>  _ar;
    int _ar_size;
    cin >> _ar_size;
    for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp); 
    }
    partition(_ar, 0, _ar.size()-1);
    return 0;
}

