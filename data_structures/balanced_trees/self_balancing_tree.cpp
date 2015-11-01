#include <iostream>
#include <vector>

using namespace std;

struct node {
	int val;            //value
	struct node* left;  //left child
	struct node* right; //right child
	int ht;             //height of the node
} node;

void add_node(struct node *root, int new_val, vector<struct node *> &parents) {
	if (new_val == root->val)
		return;
	parents.push_back(root);
	if (new_val < root->val) {
		if (root->left)
			add_node(root->left, new_val, parents);
		else {
			root->left = new struct node;
			root->left->val = new_val;
			root->left->left = root->left->right = nullptr;
			root->left->ht = 0;
		}
	} else {
		if (root->right)
			add_node(root->right, new_val, parents);
		else {
			root->right = new struct node;
			root->right->val = new_val;
			root->right->left = root->right->right = nullptr;
			root->right->ht = 0;
		}
	}
}

struct node *insert(struct node *root, int new_val) {
	if (!root) {
		root = new struct node;
		root->val = new_val;
		root->left = root->right = nullptr;
		root->ht = 0;
		return root;
	}
	vector<struct node *> parents;
	add_node(root, new_val, parents);
	// update <ht> of parents and rotate if necessary
	int height = 1;
	for (int ii = parents.size()-1; ii >= 0; --ii) {
		struct node *curr = parents[ii];
		curr->ht = max(curr->ht, height++);
	}
	return root;
}

void print_tree(struct node *root) {
	if (!root)
		return;
	cout << root->val << " (" << root->ht << ")" << endl;
	if (root->left)
		cout << "\t=> " << root->left->val << endl;
	if (root->right)
		cout << "\t=> " << root->right->val << endl;
	if (root->left)
		print_tree(root->left);
	if (root->right)
		print_tree(root->right);
}

void free_tree(struct node *root) {
	free_tree(root->left);
	free_tree(root->right);
	delete root;
}

int main() {
	struct node *root = nullptr;
	root = insert(root, 3);
	root = insert(root, 2);
	root = insert(root, 4);
	root = insert(root, 5);
	root = insert(root, 6);

	print_tree(root);
	free_tree(root);
	return 0;
}
