#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

vector<int> preorder(TreeNode* root) {
    vector<int> preorder;

    if (!root) return preorder;

    TreeNode* cur = root;

    while (cur){
        if (cur->left == nullptr){
            preorder.push_back(cur->data);
            cur = cur->right;
        }
        else{
            TreeNode* prev = cur->left;

            while (prev->right && prev->right != cur){
                prev = prev->right;
            }

            if (prev->right == nullptr){
                prev->right = cur;
                preorder.push_back(cur->data);
                cur = cur->left;
            }
            else{
                prev->right = nullptr;
                cur = cur->right;
            }
        }
    }

    return preorder;
}