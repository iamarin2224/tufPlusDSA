#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

int height(TreeNode* root){
    if (root == nullptr) return 0;

    int left = height(root->left);
    int right = height(root->right);

    return 1+max(left, right);
}

int diameterOfBinaryTree(TreeNode* root) {
    if (root == nullptr) return 0;

    int left = height(root->left);
    int right = height(root->right);

    int dia = left+right;
    int diaLeft = diameterOfBinaryTree(root->left);
    int diaRight = diameterOfBinaryTree(root->right);

    return max(dia, max(diaLeft, diaRight));
}

//With optimisation
int height(TreeNode* root, int& diameter){
    if (root == nullptr) return 0;

    int left = height(root->left, diameter);
    int right = height(root->right, diameter);

    diameter = max(diameter, left+right);

    return 1+max(left, right);
}

int diameterOfBinaryTree(TreeNode* root) {
    int diameter = 0;

    height(root, diameter);

    return diameter;
}