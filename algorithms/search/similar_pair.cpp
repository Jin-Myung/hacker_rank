#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <assert.h>

using namespace std;

struct node_t {
    node_t(int _v) : v(_v) { }
    int v;
    vector<node_t> child;
    node_t *get_sub_node(int a) {
        if (a == v) {
            return this;
        }
        for (int ii = 0; ii < child.size(); ++ii) {
            node_t *ret = child[ii].get_sub_node(a);
            if (ret) {
                return ret;
            }
        }
        return nullptr;
    }
    void add_child(int b) {
        child.push_back(b);
    }
};

void add_pair(node_t &root, int s, int d) {
    node_t *par = root.get_sub_node(s);
    if (par) {
        par->add_child(d);
    } else {
        par = root.get_sub_node(d);
        assert(par);
        par->add_child(s);
    }
}

void print_tree(node_t &node) {
    for (int ii = 0; ii < node.child.size(); ++ii) {
        cout << node.v << "->" << node.child[ii].v << endl;
        print_tree(node.child[ii]);
    }
}

void get_num_sim_pair(
        node_t &node,
        int v,
        int T,
        int &num_sim_pair
        ) {
    if (node.v != v && abs(v-node.v) <= T) {
        ++num_sim_pair;
    }
    for (int ii = 0; ii < node.child.size(); ++ii) {
        get_num_sim_pair(node.child[ii], v, T, num_sim_pair);
    }
    for (int ii = 0; ii < node.child.size(); ++ii) {
        get_num_sim_pair(node.child[ii], node.child[ii].v, T, num_sim_pair);
    }
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n, T;
    cin >> n >> T;
    int p, c;
    cin >> p >> c;
    node_t root(p);
    add_pair(root, p, c);
    for (int ii = 1; ii < n-1; ++ii) {
        int p, c;
        cin >> p >> c;
        add_pair(root, p, c);
    }
//    print_tree(root);
    int num_sim_pair = 0;
    get_num_sim_pair(root, root.v, T, num_sim_pair);
    cout << num_sim_pair << endl;
    return 0;
}
