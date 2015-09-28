#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin >> n;
    vector<string> mtx;
    while (n--) {
        string temp;
        cin >> temp;
        mtx.push_back(temp);
    }
    vector<string> out_mtx = mtx;
    for (vector<string>::size_type ii = 1; ii < out_mtx.size()-1; ii++) {
        string &row = out_mtx[ii];
        for (string::size_type jj = 1; jj < row.length()-1; jj++) {
            if (
                row[jj] > mtx[ii][jj-1] 
                && row[jj] > mtx[ii][jj+1] 
                && row[jj] > mtx[ii-1][jj] 
                && row[jj] > mtx[ii+1][jj] 
                ) {
                row[jj] = 'X';
            }
        }
    }
    for (const auto &row : out_mtx) {
        cout << row << endl;
    }
    return 0;
}
