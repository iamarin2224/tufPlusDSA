#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

struct Node {
    int size, maxNode, minNode;

    Node(int size, int maxNode, int minNode){
        this->size = size;
        this->maxNode = maxNode;
        this->minNode = minNode;
    }
};

Node largestBSTHelper(TreeNode* root){
    if (!root){
        //size 0, with max as very low and min as very high
        return Node(0, INT_MIN, INT_MAX);
    }

    Node left = largestBSTHelper(root->left);
    Node right = largestBSTHelper(root->right);

    if (left.maxNode < root->data && right.minNode > root->data){
        return Node(
            right.size+left.size+1, 
            //comparision required for over ridding null root cases value 
            max(root->data, right.maxNode), 
            min(root->data, left.minNode)
        );
    }

    return Node(max(left.size, right.size), INT_MAX, INT_MIN);
}

int largestBST(TreeNode* root){
    return largestBSTHelper(root).size;
}