#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <assert.h>

using namespace std;

struct tn_t {
public:
    tn_t(int _idx, int _w, struct tn_t *_p) : idx(_idx), weight_sum(_w), parent(_p) { }
    void add_child(int child_idx, int child_weight) { child.push_back(tn_t(child_idx, child_weight, this)); update_weight(child_weight); }
    void update_weight(int added_weight ) { weight_sum += added_weight; if (parent) { parent->update_weight(added_weight); } }
public:
    int idx;
    int weight_sum = 0;
    vector<struct tn_t> child;
    struct tn_t *parent;
};

struct tn_t *find_parent(struct tn_t &node, int idx) {
    if (node.idx == idx) {
        return &node;
    }
    for (int ii = 0; ii < node.child.size(); ++ii) {
        struct tn_t *ret = find_parent(node.child[ii], idx);
        if (ret) {
            return ret;
        }
    }
    return nullptr;
}

void add_node(
        struct tn_t &root,
        const int s,
        const int d,
        const vector<int> &w,
        vector<pair<int, int>> &pairs_not_processed
        ) {
    struct tn_t *par = find_parent(root, s);
    if (par) {
        par->add_child(d, w[d-1]);
    } else {
        par = find_parent(root, d);
        if (!par) {
            pairs_not_processed.push_back(make_pair(s, d));
            return;
        }
        par->add_child(s, w[s-1]);
    }
}

void print_node(const struct tn_t &node) {
    cout << node.idx << ": " << node.weight_sum << endl;
    for (int ii = 0; ii < node.child.size(); ++ii) {
        print_node(node.child[ii]);
    }    
}

void get_min_diff(const struct tn_t &node, const int root_sum, int &min_diff) {
    int diff = abs(root_sum - 2 * node.weight_sum);
    if (diff < min_diff) {
        min_diff = diff;
    }
//    cout << node.idx << ": " << diff << endl;
    for (int ii = 0; ii < node.child.size(); ++ii) {
        get_min_diff(node.child[ii], root_sum, min_diff);
    }    
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    vector<int> w;
    for (int ii = 0; ii < N; ++ii) {
        int temp;
        cin >> temp;
        w.push_back(temp);
    }
    int s, d;
    cin >> s >> d;
    struct tn_t root(s, w[s-1], nullptr);
    vector<pair<int, int>> pairs_not_processed;
    add_node(root, s, d, w, pairs_not_processed);
    for (int ii = 1; ii < N-1; ++ii) {
        int s, d;
        cin >> s >> d;
        add_node(root, s, d, w, pairs_not_processed);
    }
    while (!pairs_not_processed.empty()) {
        vector<pair<int, int>> pairs_not_processed2;
        for (int ii = 0; ii < pairs_not_processed.size(); ++ii) {
            add_node(root, pairs_not_processed[ii].first, pairs_not_processed[ii].second, w, pairs_not_processed2);
        }
        pairs_not_processed = pairs_not_processed2;
    }
//    print_node(root);
    int min_diff = root.weight_sum;
    get_min_diff(root, root.weight_sum, min_diff);
    cout << min_diff << endl;
    return 0;
}
