#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

//My Code
void maxDepthHelper(TreeNode* root, int& maxDepth, int curDepth){
    if (root == nullptr){
        maxDepth = max(maxDepth, curDepth-1);
        return;
    }

    maxDepthHelper(root->left, maxDepth, curDepth+1);
    maxDepthHelper(root->right, maxDepth, curDepth+1);
}

int maxDepth(TreeNode* root) {
    int ans = INT_MIN;
    int curDepth = 1;

    maxDepthHelper(root, ans, curDepth);

    return ans;
}

//TUF Code (Better Code Quality)
int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return 1+max(left, right);
}
