#include <iostream>
#include <map>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

vector<int> rightSideView(TreeNode *root){
    vector<int> result;

    if (!root) return result;

    //stores `row-node` pair
    map<int, int> nodeMap;

    //stores `node-row` pair
    queue<pair<TreeNode*, int>> q;

    q.push({root, 0});

    while(!q.empty()){
        auto p = q.front();
        q.pop();

        TreeNode* node = p.first;
        int row = p.second;

        nodeMap[row] = node->data;
                
        if (node->left){
            q.push({node->left, row+1});
        }
        if (node->right){
            q.push({node->right, row+1});
        }
    }

    for (auto& it: nodeMap){
        result.push_back(it.second);
    }

    return result;
}

//Shorter Recursive Code
void recursionRight(TreeNode* root, int level, vector<int>& res) {
    if (root == nullptr) {
        return;
    }
    
    //if level == res.size() means level is encountered for first so we store it
    //else level was seen previously and san be ignored as we are going to right first
    if (res.size() == level) {
        res.push_back(root->data);
    }
    
    recursionRight(root->right, level + 1, res);
    recursionRight(root->left, level + 1, res);
}

vector<int> rightSideView(TreeNode *root){
    vector<int> result;

    recursionRight(root, 0, result);

    return result;
}