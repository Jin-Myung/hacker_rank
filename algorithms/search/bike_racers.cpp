#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

struct pos_t {
    pos_t(int _x, int _y) : x(_x), y(_y) { }
    int x;
    int y;
};

struct dist_t {
    dist_t(int _r, int _k, long dist) : br_idx(_r), bk_idx(_k), sqr_dist(dist) { }
    bool operator<(const dist_t &rhs) {
        return sqr_dist < rhs.sqr_dist;
    }
    int br_idx;
    int bk_idx;
    long sqr_dist;
};

int get_num_pairs_ready(
        const map<int, int> &br_cnt,
        const map<int, int> &bk_cnt
        ) {
    int num_dup = 0;
//    for (map<int, int>::const_iterator it = br_cnt.begin(); it != br_cnt.end(); ++it) {
//        if (it->second > 1) {
//            num_dup += (it->second - 1);
//        }
//    }
    return min(br_cnt.size(), bk_cnt.size())-num_dup;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N, M, K;
    cin >> N >> M >> K;
    vector<pos_t> br;
    vector<pos_t> bk;
    while (N--) {
        int x, y;
        cin >> x >> y;
        br.push_back(pos_t(x, y));
    }
    while (M--) {
        int x, y;
        cin >> x >> y;
        bk.push_back(pos_t(x, y));
    }
    vector<dist_t> dist;
    for (int ii = 0; ii < br.size(); ++ii) {
        for (int jj = 0; jj < bk.size(); ++jj) {
            dist.push_back(dist_t(ii, jj, (br[ii].x-bk[jj].x)*(br[ii].x-bk[jj].x)+(br[ii].y-bk[jj].y)*(br[ii].y-bk[jj].y)));
        }
    }
    sort(dist.begin(), dist.end());
    map<int, int> br_cnt;
    map<int, int> bk_cnt;
    for (int ii = 0; ii < dist.size(); ++ii) {
        br_cnt[dist[ii].br_idx]++;
        bk_cnt[dist[ii].bk_idx]++;
//        for (map<int, int>::const_iterator it = br_cnt.begin(); it != br_cnt.end(); ++it) {
//            cout << "[" << it->first << "] " << it->second << endl;
//        }
//        cout << endl;
//        for (map<int, int>::const_iterator it = bk_cnt.begin(); it != bk_cnt.end(); ++it) {
//            cout << "[" << it->first << "] " << it->second << endl;
//        }
//        cout << endl;
        int num_pairs = get_num_pairs_ready(br_cnt, bk_cnt);
//        cout << num_pairs << endl;
        if (num_pairs == K) {
            cout << dist[ii].sqr_dist << endl;
            break;
        }
    }
    return 0;
}
