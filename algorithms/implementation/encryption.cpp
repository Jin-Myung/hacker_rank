#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string str;
    cin >> str;
    int sqrt_len = sqrt(str.length());
    int gap;
    if (sqrt_len*sqrt_len >= str.length()) {
        gap = sqrt_len;
    } else {
        gap = sqrt_len+1;
    }
    for (int ii = 0; ii < gap; ii++) {
        int jj = ii;
        string seg;
        while (jj < str.length()) {
            seg += str[jj];
            jj += gap;
        }
        cout << seg << " ";
    }
    cout << endl;
    return 0;
}
