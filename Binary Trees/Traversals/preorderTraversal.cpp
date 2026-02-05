#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

void preorderHelper(TreeNode* root, vector<int>& ans){
    if (root == nullptr) return;

    ans.push_back(root->data);
    preorderHelper(root->left, ans);
    preorderHelper(root->right, ans);
}

vector<int> preorder(TreeNode* root){
    vector<int> ans;
    preorderHelper(root, ans);

    return ans;
}

//Iterative Appraoch
vector<int> preorder(TreeNode* root){
    vector<int> ans;
    
    if (root == nullptr){
        return ans;
    }

    stack<TreeNode*> st;

    st.push(root);

    while (!st.empty()){
        //Access the current by popping out and adding to ans
        TreeNode* node = st.top();
        st.pop();

        ans.push_back(node->data);

        //push the right first, so while pop left comes out first
        if (node->right){
            st.push(node->right);
        }
        if (node->left){
            st.push(node->left);
        }
    }

    return ans;
}