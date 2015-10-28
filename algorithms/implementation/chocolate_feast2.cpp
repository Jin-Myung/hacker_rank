#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, C, M;
        cin >> N >> C >> M;
        int num = N/C;
        int out = num;
        while (1) {
            int div = num / M;
            int mod = num % M;
            if (div == 0) {
                break;
            }
            out += div;
            num = div + mod;
        }
        cout << out << endl;
    }
    return 0;
}

