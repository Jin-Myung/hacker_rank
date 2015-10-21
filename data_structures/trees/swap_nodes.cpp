#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <deque>
#include <assert.h>

using namespace std;

struct Node {
    Node(int _idx) : idx(_idx) { }
public:
    int idx;
    Node *left;
    Node *right;
};

void swap_node(Node *node, int depth, int sidx) {
    if (nullptr == node) {
        return;
    }
    if (depth % sidx == 0) {
        swap(node->left, node->right);
    }
    swap_node(node->left, depth+1, sidx);
    swap_node(node->right, depth+1, sidx);
}

void print_node(Node *node) {
    if (nullptr == node) {
        return;
    }
    print_node(node->left);
    cout << node->idx << " ";
    print_node(node->right);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int N;
    cin >> N;
    deque<Node *> nodeq;
    Node *root_node = new Node(1);
    nodeq.push_back(root_node);
    while (N--) {
        assert(nodeq.empty() == false);
        Node *node = nodeq.front();
        nodeq.pop_front();
        int l, r;
        cin >> l >> r;
        if (l != -1) {
            Node *left = new Node(l);
            node->left = left;
            nodeq.push_back(left);
        } else {
            node->left = nullptr;
        }
        if (r != -1) {
            Node *right = new Node(r);
            node->right = right;
            nodeq.push_back(right);
        } else {
            node->right = nullptr;
        }
    }
    cin >> N;
    while (N--) {
        int K;
        cin >> K;
        swap_node(root_node, 1, K);
        print_node(root_node);
        cout << "\n";
    }
    return 0;
}

