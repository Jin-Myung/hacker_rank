#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int out = 2;
        for (int ii = 0; ii < N/2; ++ii) {
            out <<= 1;
        }
        out -= 1;
        if (N & 1) {
            out <<= 1;
        }
        cout << out << endl;
    }
}

