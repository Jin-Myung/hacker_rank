#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int get_mtx_ele(
        const int num_col,
        const vector<int> &mtx,
        const int row,
        const int col
        ) {
    return mtx[row*num_col+col];
}

int build_strips(
        const int M,
        const int N,
        const vector<int> &mtx,
        vector<deque<int> > &strips
        ) {
    int num_strips = (M <= N) ? M/2 : N/2;
    for (int ii = 0; ii < num_strips; ++ii) {
        deque<int> strip;
        for (int row = ii; row < M-ii; ++row) {
            strip.push_back(get_mtx_ele(N, mtx, row, ii));
        }
        for (int col = ii+1; col < N-ii-1; ++col) {
            strip.push_back(get_mtx_ele(N, mtx, M-ii-1, col));
        }
        for (int row = M-ii-1; row >= ii; --row) {
            strip.push_back(get_mtx_ele(N, mtx, row, N-ii-1));
        }
        for (int col = N-ii-2; col >= ii+1; --col) {
            strip.push_back(get_mtx_ele(N, mtx, ii, col));
        }
/*        for (auto ele : strip) {
            cout << ele << " ";
        }
        cout << endl;
*/        strips.push_back(strip);
    }
    return 0;
}

int rotate_strip(deque<int> &strip, long R) {
    R %= strip.size();
    while (R--) {
        int end = strip.back();
        strip.pop_back();
        strip.push_front(end);
    }
    return 0;
}

int rotate_strips(vector<deque<int> > &strips, const long R) {
    for (auto &strip : strips) {
        rotate_strip(strip, R);
/*        for (auto ele : strip) {
            cout << ele << " ";
        }
        cout << endl;
*/    }
    return 0;
}

int set_mtx_ele(
        const int num_col,
        vector<int> &mtx,
        const int row,
        const int col,
        const int value
        ) {
    return mtx[row*num_col+col] = value;
}

int build_mtx(
        const int M,
        const int N,
        const vector<deque<int> > &strips,
        vector<int> &mtx
        ) {
    for (auto ii = 0; ii < strips.size(); ++ii) {
        const deque<int> &strip = strips[ii];
        int idx = 0;
        for (int row = ii; row < M-ii; ++row) {
            set_mtx_ele(N, mtx, row, ii, strip[idx++]);
        }
        for (int col = ii+1; col < N-ii-1; ++col) {
            set_mtx_ele(N, mtx, M-ii-1, col, strip[idx++]);
        }
        for (int row = M-ii-1; row >= ii; --row) {
            set_mtx_ele(N, mtx, row, N-ii-1, strip[idx++]);
        }
        for (int col = N-ii-2; col >= ii+1; --col) {
            set_mtx_ele(N, mtx, ii, col, strip[idx++]);
        }
    }
    return 0;
}

int print_mtx(
        const int M,
        const int N,
        const vector<int> &mtx
        ) {
    for (int row = 0; row < M; row++) {
        for (int col = 0; col < N; col++) {
            cout << get_mtx_ele(N, mtx, row, col) << " ";
        }
        cout << endl;
    }
    return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int M, N;
    long R;
    cin >> M >> N >> R;
    vector<int> mtx;
    for (int r = 0; r < M; r++) {
        for (int c = 0; c < N; c++) {
            int temp;
            cin >> temp;
            mtx.push_back(temp);
        }
    }
    vector<deque<int> > strips;
    build_strips(M, N, mtx, strips);
    rotate_strips(strips, R);
    vector<int> output_mtx(M*N, 0);
    build_mtx(M, N, strips, output_mtx);
    print_mtx(M, N, output_mtx);
    return 0;
}
