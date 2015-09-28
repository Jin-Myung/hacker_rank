#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_matched(
        const vector<string> &G,
        const vector<string> &P,
        const int ridx,
        const int cidx
        ) {
    for (int ii = 0; ii < P.size(); ++ii) {
        if (P[ii] != G[ii+ridx].substr(cidx, P[ii].size())) {
            return false;
        }
    }
    return true;
}

int grid_search() {
    int R, C;
    cin >> R >> C;
    vector<string> G;
    for (int ii = 0; ii < R; ++ii) {
        string temp;
        cin >> temp;
        G.push_back(temp);
    }
    int r, c;
    cin >> r >> c;
    vector<string> P;
    for (int ii = 0; ii < r; ++ii) {
        string temp;
        cin >> temp;
        P.push_back(temp);
    }
    string matched = "NO";
    for (int ii = 0; ii <= R-r; ++ii) {
        for (int jj = 0; jj <= C-c; jj++) {
            if (is_matched(G, P, ii, jj)) {
                matched = "YES";
                break;
            }
        }
    }
    cout << matched << endl;
    return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    while (n--) {
        grid_search();
    }
    return 0;
}
