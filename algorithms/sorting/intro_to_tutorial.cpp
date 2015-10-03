#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int V, n;
    vector<int> ar;

    cin >> V >> n;
    while(n--) {
        int temp;
        cin >> temp;
        ar.push_back(temp);
    }

    for (decltype(ar.size()) ii = 0; ii < ar.size(); ++ii) {
        if (ar[ii] == V) {
            cout << ii << endl;
            break;
        }
    }
    return 0;
}
