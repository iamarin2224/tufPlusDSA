#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

TreeNode* recurBuild(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& mpp){
    if (postStart > postEnd || inStart > inEnd){
        return nullptr;
    }

    TreeNode* root = new TreeNode(postorder[postEnd]);

    int inRoot = mpp[root->data];
    int nodesLeft = inRoot-inStart;

    root->left = recurBuild(postorder, postStart, postStart+nodesLeft-1, inorder, inStart, inRoot-1, mpp);
    root->right = recurBuild(postorder, postStart+nodesLeft, postEnd-1, inorder, inRoot+1, inEnd, mpp);

    return root;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    unordered_map<int, int> mpp;

    for (int i=0; i<inorder.size(); i++){
        mpp[inorder[i]] = i; 
    }

    TreeNode* root = recurBuild(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, mpp);

    return root;
}