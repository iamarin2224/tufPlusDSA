#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

void postorderHelper(TreeNode* root, vector<int>& ans){
    if (root == nullptr) return;

    postorderHelper(root->left, ans);
    postorderHelper(root->right, ans);
    ans.push_back(root->data);
}

vector<int> postorder(TreeNode* root){
    vector<int> ans;
    postorderHelper(root, ans);

    return ans;
}

//Iterative Approach
vector<int> postorder(TreeNode* root){
    vector<int> ans;
    
    if (root == nullptr){
        return ans;
    }

    stack<TreeNode*> st;

    st.push(root);

    //we do root->right->left then reverse it to get left->right->root
    while (!st.empty()){
        //Access the current by popping out and adding to ans
        TreeNode* node = st.top();
        st.pop();

        ans.push_back(node->data);

        //push the left first
        if (node->left){
            st.push(node->left);
        }
        if (node->right){
            st.push(node->right);
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}