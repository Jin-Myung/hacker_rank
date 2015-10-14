#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool is_marked(vector<vector<char> > &mtx, const int ii, const int jj) {
    return 0x1 & mtx[ii][jj];
}

bool is_visited(vector<vector<char> > &mtx, const int ii, const int jj) {
    return 0x2 & mtx[ii][jj];
}

void set_visited(vector<vector<char> > &mtx, const int ii, const int jj) {
    mtx[ii][jj] |= 0x2;
}

void get_region_size(
        vector<vector<char> > &mtx,
        const int ii,
        const int jj,
        int &region_size
        ) {
    set_visited(mtx, ii, jj);
    if (!is_marked(mtx, ii, jj)) {
        return;
    }
    ++region_size;
    if (ii > 0 && !is_visited(mtx, ii-1, jj)) {
        get_region_size(mtx, ii-1, jj, region_size);
    }
    if (ii < mtx.size()-1 && !is_visited(mtx, ii+1, jj)) {
        get_region_size(mtx, ii+1, jj, region_size);
    }
    if (jj > 0 && !is_visited(mtx, ii, jj-1)) {
        get_region_size(mtx, ii, jj-1, region_size);
    }
    if (jj < mtx[ii].size()-1 && !is_visited(mtx, ii, jj+1)) {
        get_region_size(mtx, ii, jj+1, region_size);
    }
    if (ii > 0 && jj > 0 && !is_visited(mtx, ii-1, jj-1)) {
        get_region_size(mtx, ii-1, jj-1, region_size);
    }
    if (ii > 0 && jj < mtx[ii].size()-1 && !is_visited(mtx, ii-1, jj+1)) {
        get_region_size(mtx, ii-1, jj+1, region_size);
    }
    if (ii < mtx.size()-1 && jj > 0 && !is_visited(mtx, ii+1, jj-1)) {
        get_region_size(mtx, ii+1, jj-1, region_size);
    }
    if (ii < mtx.size()-1 && jj < mtx[ii].size()-1 && !is_visited(mtx, ii+1, jj+1)) {
        get_region_size(mtx, ii+1, jj+1, region_size);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int m, n;
    cin >> m >> n;
    vector<vector<char> > mtx;
    for (int ii = 0; ii < m; ++ii) {
        vector<char> row;
        for (int jj = 0; jj < n; ++jj) {
            int temp;
            cin >> temp;
            row.push_back(temp);
        }
        mtx.push_back(row);
    }
    int size_largest = 0;
    for (int ii = 0; ii < m; ++ii) {
        for (int jj = 0; jj < n; ++jj) {
            if (is_marked(mtx, ii, jj) && !is_visited(mtx, ii, jj)) {
                int region_size = 0;
                get_region_size(mtx, ii, jj, region_size);
                if (region_size > size_largest) {
                    size_largest = region_size;
                }
            }
        }
    }
    cout << size_largest << endl;
    return 0;
}
