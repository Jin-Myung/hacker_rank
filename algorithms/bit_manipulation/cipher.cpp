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
    for (int ii = 0; ii < N; ++ii) {
        bool next = get_next_value(str[ii], output, K-1);
        if (next) {
            output += '1';
        } else {
            output += '0';
        }
    }
    cout << output << endl;
    return 0;
}
