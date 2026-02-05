#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

void inorderHelper(TreeNode* root, vector<int>& ans){
    if (root == nullptr) return;

    inorderHelper(root->left, ans);
    ans.push_back(root->data);
    inorderHelper(root->right, ans);
}

vector<int> inorder(TreeNode* root){
    vector<int> ans;
    inorderHelper(root, ans);

    return ans;
}

//Iterative Inorder (buildup on recursive)
vector<int> inorder(TreeNode* root){
    stack<TreeNode*> st;
    vector<int> ans;

    TreeNode* node = root;
    
    while (true){
        //keep on adding left node to stack (just like recursive stack)
        if (node != nullptr){
            st.push(node);
            node = node->left;
        }
        //if null, then go back and print the top most node and go to right
        else{
            if (st.empty()){
                break;
            }

            node = st.top();
            st.pop();

            ans.push_back(node->data);

            node = node->right;
        }
    }

    return ans;
}