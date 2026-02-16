#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr){
        TreeNode* node = new TreeNode(val);
        return node;
    }

    if (val < root->data){
        root->left = insertIntoBST(root->left, val);
    }
    else{
        root->right = insertIntoBST(root->right, val);
    }

    return root;
}