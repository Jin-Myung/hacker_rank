using namespace std;

typedef struct node
{
   int data;
   node * left;
   node * right;
}node;

node * lca(node * root, int v1,int v2)
{
    while (root) {
        if (nullptr == root->left && nullptr == root->right) {
            return root;
        }
        if (v1 < root->data && v2 < root->data) {
            if (nullptr == root->left) {
                return root;
            }
            root = root->left;
        } else if (v1 > root->data && v2 > root->data) {
            if (nullptr == root->right) {
                return root;
            }
            root = root->right;
        } else {
            return root;
        }
    }
    return nullptr;
}

int main() {
    return 0;
}
