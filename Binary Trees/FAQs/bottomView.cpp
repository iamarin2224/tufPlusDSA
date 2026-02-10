#include <iostream>
#include <map>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

vector<int> bottomView(TreeNode *root){
    vector<int> result;

    if (!root) return result;

    //stores `col-node` pair
    map<int, int> nodeMap;

    //stores `node-col` pair
    queue<pair<TreeNode*, int>> q;

    q.push({root, 0});

    while(!q.empty()){
        auto p = q.front();
        q.pop();

        TreeNode* node = p.first;
        int col = p.second;

        nodeMap[col] = node->data;
        
        if (node->left){
            q.push({node->left, col-1});
        }
        if (node->right){
            q.push({node->right, col+1});
        }
    }

    for (auto& it: nodeMap){
        result.push_back(it.second);
    }

    return result;
}