#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int stones() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a == b) {
        cout << (n-1)*a << endl;
        return 0;
    }
    if (a > b) { swap(a, b); }
    for (int ii = 0; ii < n; ++ii) {
        int sum = 0;
        sum += ii * b;
        sum += (n-1-ii) * a;
        cout << sum << " ";
    }
    cout << endl;
    return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    while (n--) {
        stones();
    }
    return 0;
}
