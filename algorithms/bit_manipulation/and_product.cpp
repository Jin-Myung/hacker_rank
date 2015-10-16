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
        uint32_t a, b;
        cin >> a >> b;
        uint32_t mask = 1 << 31;
        bool diff_found = false;
        uint32_t res = 0;
        while (mask) {
            if (diff_found) {
            } else {
                if ((mask & a) == (mask & b)) {
                    if (mask & a) {
                        res |= 1;
                    }
                } else {
                    diff_found = true;
                }
            }
            mask >>= 1;
            if (mask) {
                res <<= 1;
            }
        }
        cout << res << endl;
    }
    return 0;
}
