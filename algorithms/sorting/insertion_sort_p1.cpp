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
    for (const auto &ii : ar) {
        cout << ii << " ";
    }
    cout << endl;
}

void insertionSort(vector <int>  ar) {
    int new_ele = ar.back();
    vector<int>::iterator it = ar.end()-1;
    while (it != ar.begin()) {
        if (*(it-1) < new_ele) {
            *it = new_ele;
            print_vector(ar);
            return;
        }
        *it = *(it-1);
        print_vector(ar);
        --it;
    }
    *it = new_ele;
    print_vector(ar);
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
    insertionSort(_ar);
    return 0;
}
