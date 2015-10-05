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

void print_vector(const vector<int> &ar) {
    for (vector<int>::size_type ii = 0; ii < ar.size(); ++ii) {
        cout << ar[ii] << " ";
    }
    cout << endl;
}

void insertionSortAll(vector<int> &ar) {
    int cnt = 0;
    for (vector<int>::size_type ii = 1; ii < ar.size(); ++ii) {
        for (decltype(ii) jj = ii; jj > 0 && ar[jj] < ar[jj-1]; --jj) {
            swap(ar[jj], ar[jj-1]);
            ++cnt;
        }
    }
    cout << cnt << endl;
}

int main(void) {
    vector<int> _ar;
    int _ar_size;
    cin >> _ar_size;
    for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
        int _ar_tmp;
        cin >> _ar_tmp;
        _ar.push_back(_ar_tmp);
    }
    insertionSortAll(_ar);
    return 0;
}
