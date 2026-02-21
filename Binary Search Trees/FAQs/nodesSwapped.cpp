#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

class Solution {
    TreeNode* prev;
    TreeNode* first;
    TreeNode* middle;
    TreeNode* last;

    void inorder(TreeNode* root){
        if (!root) return;

        inorder(root->left);

        //detect violation
        if (prev != nullptr && root->data < prev->data){
            //first encounter
            if (first == nullptr){
                first = prev;
                middle = root;
            }
            //second encounter 
            else {
                last = root;
            }
        }

        prev = root; //update prev

        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        first = middle = last = nullptr;

        prev = new TreeNode(INT_MIN);

        inorder(root);

        //case of non adjacent violation
        if (first && last) swap(first->data, last->data);

        //adjacent violation
        else if (first && middle) swap(first->data,  middle->data);
    }
};