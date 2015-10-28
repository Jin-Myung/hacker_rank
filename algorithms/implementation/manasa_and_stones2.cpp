#include <iostream>

using namespace std;

int stones() {
    int n, a, b;
    cin >> n >> a >> b;
    if (a == b) {
        cout << a*(n-1) << endl;
        return 0;
    }
    if (a > b) { swap(a, b); }
    int sum = a*(n-1);
    cout << sum << " ";
    for (int ii = 0; ii < n-1; ++ii) {
        sum += (b-a);
        cout << sum << " ";
    }
    cout << endl;
    return 0;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        stones();
    }
    return 0;
}
