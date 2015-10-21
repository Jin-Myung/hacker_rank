#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int Q;
    cin >> Q;
    set<int> bag;
    while (Q--) {
        int cmd, value;
        cin >> cmd >> value;
        if (cmd == 1) {
            bag.insert(value);
        } else if (cmd == 2) {
            bag.erase(value);
        } else {
            if (bag.end() == bag.find(value)) {
                cout << "No" << endl;
            } else {
                cout << "Yes" << endl;
            }
        }
    }
    return 0;
}
