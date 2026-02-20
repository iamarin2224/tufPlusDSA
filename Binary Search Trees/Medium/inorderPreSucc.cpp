#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

void helperFn(TreeNode* root, int key, vector<int>& ans){
    if (!root){
        return;
    }

    if (root->data < key){
        ans[0] = root->data;
        helperFn(root->right, key, ans);
    }
    else if (root->data > key){
        ans[1] = root->data;
        helperFn(root->left, key, ans);
    }
    else{
        if (root->left){
            helperFn(root->left, key, ans);
        }
        if (root->right){
            helperFn(root->right, key, ans);
        }
    }
}

vector<int> succPredBST(TreeNode* root,int key){
    vector<int> ans = {-1, -1};

    helperFn(root, key, ans);

    return ans;
}