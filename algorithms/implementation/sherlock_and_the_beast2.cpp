#include <iostream>

using namespace std;

int get_num_5(int N) {
    if (N < 3) {
        return -1;
    } // if
    while (N >= 0) {
        if (N % 3 == 0) {
            return N;
        } // if
        N -= 5;
    } // while
    return -1;
}

void output_str(int N, int num_5) {
    if (-1 == num_5) {
        cout << "-1" << endl;
    } else {
        for (int ii = 0; ii < num_5; ++ii) {
            cout << "5";
        } // for
        for (int ii = 0; ii < N-num_5; ++ii) {
            cout << "3";
        } // for
        cout << endl;
    } // if
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int num_5 = get_num_5(N);
        output_str(N, num_5);
    } // while
    return 0;
}

