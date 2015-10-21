#include <string>
#include <iostream>

using namespace std;

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

char next_ch(node *root, string::const_iterator &it) {
    while (root) {
        if (nullptr == root->left && nullptr ==root->right) {
            return root->data;
        }
        if ('0' == *it++) {
            root = root->left;
        } else {
            root = root->right;
        }
    }
    return 0;
}

void decode_huff(node * root,string s)
{
    string::const_iterator it = s.begin();
    string output;
    while (it != s.end()) {
        output += next_ch(root, it);
    }
    cout << output << endl;
}

int main() {
    return 0;
}
