#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool is_visited(const vector<string> &visited, const pair<int, int> curr_loc) {
    return visited[curr_loc.first][curr_loc.second] != ' ';
}

void set_visited(vector<string> &visited, const pair<int, int> curr_loc) {
    visited[curr_loc.first][curr_loc.second] = 'v';
}

int get_num_option(
        const vector<string> &mtx,
        vector<string> &visited,
        const pair<int, int> &curr_loc
        ) {
    int ret = 0;
    if (curr_loc.first > 0 && !is_visited(visited, make_pair(curr_loc.first-1, curr_loc.second)) && (mtx[curr_loc.first-1][curr_loc.second] == '.' || mtx[curr_loc.first-1][curr_loc.second] == '*')) {
        ++ret;
    }
    if (curr_loc.first < mtx.size()-1 && !is_visited(visited, make_pair(curr_loc.first+1, curr_loc.second)) && (mtx[curr_loc.first+1][curr_loc.second] == '.' || mtx[curr_loc.first+1][curr_loc.second] == '*')) {
        ++ret;
    }
    if (curr_loc.second > 0 && !is_visited(visited, make_pair(curr_loc.first, curr_loc.second-1)) && (mtx[curr_loc.first][curr_loc.second-1] == '.' || mtx[curr_loc.first][curr_loc.second-1] == '*')) {
        ++ret;
    }
    if (curr_loc.second < mtx[curr_loc.first].length()-1 && !is_visited(visited, make_pair(curr_loc.first, curr_loc.second+1)) && (mtx[curr_loc.first][curr_loc.second+1] == '.' || mtx[curr_loc.first][curr_loc.second+1] == '*')) {
        ++ret;
    }
    return ret;
}

int get_path(
        const vector<string> &mtx,
        vector<string> &visited,
        pair<int, int> curr_loc,
        const pair<int, int> &dst,
        int num_wav
        ) {
    if (curr_loc == dst) {
        return num_wav;
    }
    if (is_visited(visited, curr_loc)) {
        return 0;
    }
    set_visited(visited, curr_loc);
    if (get_num_option(mtx, visited, curr_loc) > 1) {
        ++num_wav;
    }
    if (curr_loc.first > 0 && !is_visited(visited, make_pair(curr_loc.first-1, curr_loc.second)) && (mtx[curr_loc.first-1][curr_loc.second] == '.' || mtx[curr_loc.first-1][curr_loc.second] == '*')) {
        int ret = get_path(mtx, visited, make_pair(curr_loc.first-1, curr_loc.second), dst, num_wav);
        if (ret) {
            return ret;
        }
    }
    if (curr_loc.first < mtx.size()-1 && !is_visited(visited, make_pair(curr_loc.first+1, curr_loc.second)) && (mtx[curr_loc.first+1][curr_loc.second] == '.' || mtx[curr_loc.first+1][curr_loc.second] == '*')) {
        int ret = get_path(mtx, visited, make_pair(curr_loc.first+1, curr_loc.second), dst, num_wav);
        if (ret) {
            return ret;
        }
    }
    if (curr_loc.second > 0 && !is_visited(visited, make_pair(curr_loc.first, curr_loc.second-1)) && (mtx[curr_loc.first][curr_loc.second-1] == '.' || mtx[curr_loc.first][curr_loc.second-1] == '*')) {
        int ret = get_path(mtx, visited, make_pair(curr_loc.first, curr_loc.second-1), dst, num_wav);
        if (ret) {
            return ret;
        }
    }
    if (curr_loc.second < mtx[curr_loc.first].length()-1 && !is_visited(visited, make_pair(curr_loc.first, curr_loc.second+1)) && (mtx[curr_loc.first][curr_loc.second+1] == '.' || mtx[curr_loc.first][curr_loc.second+1] == '*')) {
        int ret = get_path(mtx, visited, make_pair(curr_loc.first, curr_loc.second+1), dst, num_wav);
        if (ret) {
            return ret;
        }
    }
    return 0;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        vector<string> mtx;
        vector<string> visited;
        pair<int, int> src;
        pair<int, int> dst;
        for (int ii = 0; ii < N; ++ii) {
            string temp;
            cin >> temp;
            string::size_type pos = temp.find('M');
            if (pos != string::npos) {
                src = make_pair(ii, pos);
            }
            pos = temp.find('*');
            if (pos != string::npos) {
                dst = make_pair(ii, pos);
            }
            mtx.push_back(temp);
            visited.push_back(string(temp.length(), ' '));
        }
        int K;
        cin >> K;
        int num_wav = get_path(mtx, visited, src, dst, 0);
        if (K == num_wav) {
            cout << "Impressed" /*<< " " << K << " " << num_wav*/ << endl;
        } else {
            cout << "Oops!" /*<< " " << K << " " << num_wav*/ << endl;
        }
    }
    return 0;
}
