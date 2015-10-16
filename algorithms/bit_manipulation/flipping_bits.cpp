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
        uint32_t n;
        cin >> n;
        n ^= 0xffffffff;
        cout << n << endl;
    }
    return 0;
}
