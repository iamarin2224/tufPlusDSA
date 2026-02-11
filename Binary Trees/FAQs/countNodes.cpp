#include <iostream>
#include <math.h>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

int findHtLeft(TreeNode* node){
    int height = 0;

    while (node){
        height++;
        node = node->left;
    }

    return height;
}

int findHtRight(TreeNode* node){
    int height = 0;

    while (node){
        height++;
        node = node->right;
    }

    return height;
}

int countNodes(TreeNode* root) { 
    if (!root) {
        return 0;
    }

    //find lh and rh, both including the root
    int lh = findHtLeft(root);
    int rh = findHtRight(root);

    //if equal then a full binary tree
    //nodes = 2^h-1 
    if (lh == rh){
        return (1 << lh) - 1;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}