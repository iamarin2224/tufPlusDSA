#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    queue<TreeNode*> q;
    vector<vector<int>> ans;

    if (!root) return ans;

    q.push(root);

    bool leftToRight = true;

    while(!q.empty()){
        int size = q.size();

        vector<int> level;

        for (int i=0; i<size; i++){
            TreeNode* node = q.front();
            q.pop();

            level.push_back(node->data);

            /*  ALT, pushing from back if not left to right
            if (leftToRight){
                level[i] = node->data;
            }
            else{
                level[size-i-1] = node->data
            }
            */

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        if (!leftToRight){
            reverse(level.begin(), level.end());
        }

        leftToRight = !leftToRight;

        ans.push_back(level);
    }

    return ans;
}