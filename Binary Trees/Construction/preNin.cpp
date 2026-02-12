#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

TreeNode* recurBuild(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& mpp){
    if (preStart > preEnd || inStart > inEnd){
        return nullptr;
    }

    TreeNode* root = new TreeNode(preorder[preStart]);

    int inRoot = mpp[root->data];
    int nodesLeft = inRoot-inStart;

    root->left = recurBuild(preorder, preStart+1, preStart+nodesLeft, inorder, inStart, inRoot-1, mpp);
    root->right = recurBuild(preorder, preStart+nodesLeft+1, preEnd, inorder, inRoot+1, inEnd, mpp);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    unordered_map<int, int> mpp;

    for (int i=0; i<inorder.size(); i++){
        mpp[inorder[i]] = i; 
    }

    TreeNode* root = recurBuild(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mpp);

    return root;
}