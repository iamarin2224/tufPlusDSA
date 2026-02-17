#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

//My Approach
bool helperFn(TreeNode* root, TreeNode*& prev){
    if (!root){
        return true;
    }

    if (!helperFn(root->left, prev)){
        return false;
    }

    if (prev != nullptr && root->data <= prev->data){
        return false;
    }
    prev = root;

    return helperFn(root->right, prev);
}

bool isBST(TreeNode* root){
    TreeNode* prev = nullptr;

    return helperFn(root, prev);
}

//TUF Approach
bool helperFn(TreeNode* root, long long min, long long max){
    if (!root) return true;

    if (root->data <= min || root->data >= max){
        return false;
    }

    return helperFn(root->left, min, root->data) && helperFn(root->right, root->data, max);
}

bool isBST(TreeNode* root){
    return (root, LLONG_MIN, LLONG_MAX);
}