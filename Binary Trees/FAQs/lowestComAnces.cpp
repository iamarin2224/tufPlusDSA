#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    //if current is null or has one of the node, this is a common ancestor
    if (!root || root==p || root==q){
        return root;
    }

    //search left and right
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    //if left is null then common ancestor on right
    if (left == nullptr){
        return right;
    }
    //if right null common ancestor on left
    else if (right == nullptr){
        return left;
    }
    //return the root if both non null, then this is the common ancestor
    else{
        return root;
    }
}