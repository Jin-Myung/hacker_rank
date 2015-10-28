#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr;
    while (N--) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    cout << arr.size() << endl;
    for (int ii = 0; ii < arr.size()-1; ++ii) {
        if (arr[ii] != arr[ii+1]) {
            cout << arr.size()-ii-1 << endl;
        }
    }
    return 0;
}

