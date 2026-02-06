#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

int pathHelper(TreeNode* root, int& path){
    if (root == nullptr) return 0;

    //max path lengths by taking leftNode and rightNode
    int leftVal = pathHelper(root->left, path);
    int rightVal = pathHelper(root->right, path);

    //calculate the max path can be formed by taking current node
    int curPath = root->data;
    if (leftVal>0) curPath += leftVal;
    if (rightVal>0) curPath += rightVal;

    //check and update path
    path = max(path, curPath);

    //return the max path possible after taking the current node
    return (max(root->data, (root->data + max(leftVal, rightVal))));
}

int maxPathSum(TreeNode* root) {
    int path = 0;

    pathHelper(root, path);

    return path;
}