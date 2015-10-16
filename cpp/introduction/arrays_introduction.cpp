#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin >> n;
    vector<int> arr;
    while (n--) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    reverse(arr.begin(), arr.end());
    for (const int & ii : arr) {
        cout << ii << " ";
    }
    cout << endl;
    return 0;
}
