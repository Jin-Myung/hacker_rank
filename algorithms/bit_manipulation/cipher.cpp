#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool get_next_value(
        const char &ch,
        const string &output,
        int K
        ) {
    int cnt = 0;
    if (ch == '1') {
        ++cnt;
    }
    if (output.length() >= K) {
        for (int ii = output.length()-K; ii < output.length(); ++ii) {
            if (output[ii] == '1') {
                ++cnt;
            }
        }
    } else {
        for (int ii = 0; ii < output.length(); ++ii) {
            if (output[ii] == '1') {
                ++cnt;
            }
        }
    }
    return (cnt % 2);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, K;
    cin >> N >> K;
    string str;
    cin >> str;
    string output;
    bool res = 0;
    for (int ii = 0; ii < N; ++ii) {
        bool next = res;
        if (str[ii] == '1') {
            next = !next;
        }
        if (next) {
            output += '1';
            res = !res;
        } else {
            output += '0';
        }
        if (output.length() >= K) {
            if (output[output.length()-K] == '1') {
                res = !res;
            }
        }
    }
    cout << output << endl;
    return 0;
}
