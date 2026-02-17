#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

TreeNode* lca(TreeNode* root, int p, int q){
    if (!root || root->data == p || root->data == q){
        return root;
    }

    if (p < root->data && q < root->data){
        return lca(root->left, p, q);
    }
    else if (p >root->data && q > root->data){
        return lca(root->right, p, q);
    }
    else{
        return root;
    }
}