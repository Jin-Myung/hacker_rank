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
#include <limits>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iostream>
using namespace std;
/*
 * Complete the function below.
 */
int maxXor(int l, int r) {
    int max_xor = 0;
    for (int ii = l; ii <= r-1; ++ii) {
        for (int jj = l+1; jj <= r; ++jj) {
            int res = ii^jj;
            if (res > max_xor) {
                max_xor = res;
            }
        }
    }
    return max_xor;
}

int main() {
    int res;
    int _l;
    cin >> _l;
    
    int _r;
    cin >> _r;
    
    res = maxXor(_l, _r);
    cout << res;
    
    return 0;
}
