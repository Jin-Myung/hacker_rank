#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int A, B;
        cin >> A >> B;
        int sqrt_A = sqrt(A);
        int sqrt_B = sqrt(B);
        if (sqrt_A*sqrt_A == A) {
            --sqrt_A;
        }
        cout << sqrt_B - sqrt_A << endl;
    }
    return 0;
}

