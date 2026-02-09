#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

void leftBoundary(TreeNode* root, vector<int>& leftBoundArr){
    if (!root || (!root->left && !root->right)){
        return;
    }

    leftBoundArr.push_back(root->data);

    if (!root->left){
        leftBoundary(root->right, leftBoundArr);
    }
    else{
        leftBoundary(root->left, leftBoundArr);
    }
}

void rightBoundary(TreeNode* root, vector<int>& rightBoundArr){
    if (!root || (!root->left && !root->right)){
        return;
    }

    rightBoundArr.push_back(root->data);

    if (!root->right){
        rightBoundary(root->left, rightBoundArr);
    }
    else{
        rightBoundary(root->right, rightBoundArr);
    }
}

void leaveNodes(TreeNode* root, vector<int>& leaveNodeArr){
    if (!root){
        return;
    }

    if (!root->left && !root->right) leaveNodeArr.push_back(root->data);
    leaveNodes(root->left, leaveNodeArr);
    leaveNodes(root->right, leaveNodeArr);
}

vector <int> boundary(TreeNode* root){
    if (!root) return {};
    if (!root->left && !root->right) return {root->data};

    vector<int> ans;
    ans.push_back(root->data);

    vector<int> leftBoundArr;
    leftBoundary(root->left, leftBoundArr);
    
    vector<int> rightBoundArr;
    rightBoundary(root->right, rightBoundArr);
    reverse(rightBoundArr.begin(), rightBoundArr.end());

    vector<int> leaveNodeArr;
    leaveNodes(root, leaveNodeArr);

    ans.insert(ans.end(), leftBoundArr.begin(), leftBoundArr.end());
    ans.insert(ans.end(), leaveNodeArr.begin(), leaveNodeArr.end());
    ans.insert(ans.end(), rightBoundArr.begin(), rightBoundArr.end());

    return ans;
}