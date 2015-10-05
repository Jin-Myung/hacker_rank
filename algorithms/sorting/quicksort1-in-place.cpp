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

void partition(vector <int> ar) {
    int pivot = ar[0];
    int lo = 0;
    int hi = ar.size();
    while (1) {
        while (ar[++lo] < pivot) {
            if (lo == ar.size()-1) {
                break;
            }
        }
        while (pivot < ar[--hi]) {
            if (hi == 0) {
                break;
            }
        }
        if (lo >= hi) {
            break;
        }
        swap(ar[lo], ar[hi]);
    }
    swap(ar[0], ar[hi]);
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
    partition(_ar);
    return 0;
}

