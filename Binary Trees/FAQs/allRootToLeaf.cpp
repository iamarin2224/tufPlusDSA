#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

void recursionHelper(TreeNode* root, vector<vector<int>>& ans, vector<int>& current){
    //return on null node condition
    if (!root) return;

    //leaf node encountered
    if (!root->left && !root->right){
        ans.push_back(current);
        return;
    }

    if (root->left){
        current.push_back(root->left->data);
        recursionHelper(root->left, ans, current);
        current.pop_back();
    }

    if (root->right){
        current.push_back(root->right->data);
        recursionHelper(root->right, ans, current);
        current.pop_back();
    }
}

vector<vector<int>> allRootToLeaf(TreeNode* root) {
    vector<vector<int>> ans;
    vector<int> current;

    if (!root) return ans;

    current.push_back(root->data);
    recursionHelper(root, ans, current);

    return ans;
}

//Alt Recursive Appraoch

void recursionHelperTUF(TreeNode* root, vector<vector<int>>& ans, vector<int>& current){
    //return on null node condition
    if (!root) return;

    current.push_back(root->data);

    //leaf node encountered
    if (!root->left && !root->right){
        ans.push_back(current);
    }
    else{
        recursionHelperTUF(root->left, ans, current);
    
        recursionHelperTUF(root->right, ans, current);
    }

    current.pop_back(); //backtrack
}

vector<vector<int>> allRootToLeaf(TreeNode* root) {
    vector<vector<int>> ans;
    vector<int> current;

    if (!root) return ans;

    recursionHelperTUF(root, ans, current);

    return ans;
}