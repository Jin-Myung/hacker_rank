#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

bool funny(const string &str) {
    for (string::size_type ii = 1; ii < str.length(); ii++) {
        if (
                abs(str[ii]-str[ii-1])
                != abs(str[str.length()-ii]-str[str.length()-ii-1])
                ) {
            return false;
        }
    }
    return true;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    while (T--) {
        string str;
        cin >> str;
        if (funny(str)) {
            cout << "Funny" << endl;
        } else {
            cout << "Not Funny" << endl;
        }
    }
    return 0;
}
