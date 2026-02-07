#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

bool checkSymmetry(TreeNode* leftNode, TreeNode* rightNode){
    if (!leftNode && !rightNode) return true;

    if (!leftNode || !rightNode) return false;

    if (leftNode->data != rightNode->data) return false;

    if (!checkSymmetry(leftNode->left, rightNode->right)) return false;

    return checkSymmetry(leftNode->right, rightNode->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root) return true;

    return checkSymmetry(root->left, root->right);
}