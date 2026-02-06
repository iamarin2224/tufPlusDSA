#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

//Brute uses N^2 TC, N for traversal ans N for height check
int height(TreeNode* root){
    if (root == nullptr) return 0;

    int left = height(root->left);
    int right = height(root->right);

    return 1+max(left, right);
}

bool isBalanced(TreeNode *root){
    if (root == nullptr) return true;

    int leftHt = height(root->left);
    int rightHt = height(root->right);

    int balanceFactor = leftHt-rightHt;

    if (abs(balanceFactor)>1) return false;

    return isBalanced(root->left) && isBalanced(root->right);
}

//Optimal (by using height check as the balance indicator)
int height(TreeNode* root){
    if (root == nullptr) return 0;

    int left = height(root->left);
    int right = height(root->right);

    //in height check itself, if it is found to be not balance we return -1, else we return height

    if (left == -1 || right == -1) return -1;

    if (abs(left-right)>1) return -1;

    return 1+max(left, right);
}

bool isBalanced(TreeNode *root){
    return height(root) != -1;
}