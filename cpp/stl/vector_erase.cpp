#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;
    vector<int> arr;
    while (N--) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    int pos;
    cin >> pos;
    arr.erase(arr.begin()+pos-1);
    int b, e;
    cin >> b >> e;
    arr.erase(arr.begin()+b-1, arr.begin()+e-1);
    cout << arr.size() << endl;
    for (const int &a : arr) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}
