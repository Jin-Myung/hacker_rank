#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int Q;
    cin >> Q;
    map<string, int> marks;
    while (Q--) {
        int cmd, mark;
        string name;
        cin >> cmd;
        if (cmd == 1) {
            cin >> name >> mark;
            marks[name] += mark;
        } else if (cmd == 2) {
            cin >> name;
            marks.erase(name);
        } else {
            cin >> name;
            cout << marks[name] << endl;
        }
    }
    return 0;
}
