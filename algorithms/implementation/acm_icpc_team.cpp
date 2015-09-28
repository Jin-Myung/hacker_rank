#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int get_num_topics(const string &a, const string &b) {
    int ret = 0;
    for (int ii = 0; ii < a.size(); ++ii) {
        if (a[ii] == '1' || b[ii] == '1') {
            ret++;
        }
    }
    return ret;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int m, n;
    cin >> m >> n;
    vector<string> topics;
    for (int ii = 0; ii < m; ++ii) {
        string topic;
        cin >> topic;
        topics.push_back(topic);
    }
    int max = -1;
    int num_max_teams = 0;
    for (int ii = 0; ii < m-1; ++ii) {
        for (int jj = ii+1; jj < m; ++jj) {
            int num_topics = get_num_topics(topics[ii], topics[jj]);
            if (num_topics > max) {
                max = num_topics;
                num_max_teams = 1;
            } else if (num_topics == max) {
                num_max_teams++;
            }
        }
    }
    cout << max << "\n" << num_max_teams;
    return 0;
}
