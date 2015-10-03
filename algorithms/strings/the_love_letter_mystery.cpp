#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        string::const_iterator b = str.begin();
        string::const_iterator e = str.end()-1;
        int count = 0;
        while (b < e) {
            count += abs(*b-*e);
            ++b;
            --e;
        }
        cout << count << endl;
    }
}
