#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    //both null, then equal
    if (!p && !q) return true;
    
    //any one of them null, not equal (the case of both null is covered early)
    if (!p || !q) return false;

    //check data of current node
    if (p->data != q->data) return false;
    
    //subtree checks
    if (!isSameTree(p->left, q->left)) return false;
    if (!isSameTree(p->right, q->right)) return false;

    return true;
}