#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

TreeNode* searchBST(TreeNode* root, int val) {
    TreeNode* cur = root;

    while (cur != nullptr){
        if (val == cur->data){
            return cur;
        }
        else if (val < cur->data){
            cur = cur->left;
        }
        else{
            cur = cur->right;
        }
    }

    return nullptr;
}