#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

TreeNode* bstHelper(vector<int>& preorder, int& curIdx, int bound) {
    if (curIdx == preorder.size() || preorder[curIdx] >= bound){
        return nullptr;
    }

    TreeNode* root = new TreeNode(preorder[curIdx++]);

    root->left = bstHelper(preorder, curIdx, root->data);

    root->right = bstHelper(preorder, curIdx, bound);

    return root;
}

TreeNode* bstFromPreorder(vector<int>& preorder) {
    int index = 0;

    return bstHelper(preorder, index, INT_MAX);
}