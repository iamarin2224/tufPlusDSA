#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

TreeNode* inorderPre(TreeNode* node){
    node = node->left;

    while (node->right != nullptr){
        node = node->right;
    }

    return node;
}

TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr){
        return root;
    }
    
    else if (key < root->data){
        root->left = deleteNode(root->left, key);
    }

    else if (key > root->data){
        root->right = deleteNode(root->right, key);
    }

    else{
        //Leaf Node
        if (!root->left && !root->right){
            delete root;
            return nullptr;
        }   

        //No left subtree
        else if (!root->left){
            TreeNode* temp = root->right;
            delete root;

            return temp;
        }

        //No right subtree
        else if (!root->right){
            TreeNode* temp = root->left;
            delete root;

            return temp;
        }

        //If node with both children, swap with it's inorder predecessor
        else{
            TreeNode* prevNode = inorderPre(root);
            root->data = prevNode->data;

            root->left = deleteNode(root->left, prevNode->data);
        }
    }

    return root;
}