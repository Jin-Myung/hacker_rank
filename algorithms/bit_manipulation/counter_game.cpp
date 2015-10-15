#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//int get_largest_power_of_two(unsigned long long N) {
//    int num_shift = 0;
//    while (N) {
//        N >>= 1;
//        ++num_shift;
//    }
//    unsigned long long ret = 1;
//    return ret << (num_shift-1);
//}
//
//void counter_game() {
//    unsigned long long N;
//    cin >> N;
//    int num_turn = 0;
//    while (N > 1) {
//        if (0 == (N & (N-1))) {
//            // power of two
//            N /= 2;
//        } else {
//            N -= get_largest_power_of_two(N);
//        }
//        ++num_turn;
//    }
//    if (num_turn % 2) {
//        cout << "Louise" << endl;
//    } else {
//        cout << "Richard" << endl;
//    }
//}

void counter_game() {
    unsigned long long N;
    cin >> N;
    int num_tail_zero = 0;
    int num_ones = 0;
    bool one_reached = false;
    while (N) {
        if (N & 1) {
            one_reached = true;
            ++num_ones;
        } else {
            if (false == one_reached) {
                ++num_tail_zero;
            }
        }
        N >>= 1;
    }
//    cout << num_tail_zero << " " << num_ones << endl;
    if ((num_tail_zero + num_ones) % 2) {
        cout << "Richard" << endl;
    } else {
        cout << "Louise" << endl;
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int T;
    cin >> T;
    while (T--) {
        counter_game();
    }
    return 0;
}
