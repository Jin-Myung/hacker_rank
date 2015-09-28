#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int do_trick() {
    long b, w;
    cin >> b >> w;
    long x, y, z;
    cin >> x >> y >> z;

    long num_exp = b;
    long min = y;
    long max = x;
    if (x < y) {
        num_exp = w;
        min = x;
        max = y;
    }
//    cout << min << " " << z << " " << max << " " << num_exp << endl;
    if (min + z < max) {
        cout << (b+w)*min + num_exp*z << endl;
    } else {
        cout << b*x + w*y << endl;
    }
    return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int t;
    cin >> t;
    while (t--) {
        do_trick();
    }
    return 0;
}
