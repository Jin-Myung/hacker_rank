#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> arr;
    while (N--) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    reverse(arr.begin(), arr.end());
    copy(arr.begin(), arr.end(), ostream_iterator<int>(cout, " "));
    cout << "\n";
    return 0;
}
