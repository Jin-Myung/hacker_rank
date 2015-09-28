#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int get_num_digits(long num) {
    int ret = 0;
    while (num) {
        ret++;
        num /= 10;
    }
    return ret;
}

int get_half_base10(const long num) {
    int num_digits = get_num_digits(num);
    int num_half_digits = (num_digits+1)/2;
//    cout << num_digits << " " << num_half_digits << endl;
    int ret = 1;
    for (int ii = 0; ii < num_half_digits; ++ii) {
        ret *= 10;
    }
    return ret;
}

bool is_kn(const long num) {
    long sqr = num*num;
    int half_base10 = get_half_base10(sqr);
//    cout << sqr << " " << half_base10 << endl;
    if (num == sqr/half_base10 + sqr%half_base10) {
        return true;
    }
    return false;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long min, max;
    cin >> min >> max;
    vector<long> found;
    for (long ll = min; ll <= max; ll++) {
        if (is_kn(ll)) {
            found.push_back(ll);
        }
    }
    if (found.empty()) {
        cout << "INVALID RANGE" << endl;
    } else {
        for (auto ll : found) {
            cout << ll << " ";
        }
        cout << endl;
    }
    return 0;
}
