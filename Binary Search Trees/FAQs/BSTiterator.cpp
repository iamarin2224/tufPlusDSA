#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

//Brute Approach
void inorderHelper(TreeNode* root, vector<int>& inorder){
    if (!root){
        return;
    }

    inorderHelper(root->left, inorder);
    inorder.push_back(root->data);
    inorderHelper(root->right, inorder);
}

class BSTIterator{
    int i;
    int n;
    vector<int> inorder;

	public:
		BSTIterator(TreeNode* root){
            inorderHelper(root, inorder);

            this->n = inorder.size();
            this->i = -1;
		}
		
		bool hasNext(){
            if (n-i == 1) return false;

            return true;
		}
		
		int next(){
            i++;

            return inorder[i];
		}
};

//Optimal 

class BSTIterator{
    stack<TreeNode*> st;

	public:
		BSTIterator(TreeNode* root){
            while (root){
                st.push(root);
                root = root->left;
            }
		}
		
		bool hasNext(){
            return !st.empty();
		}
		
		int next(){
            TreeNode* nextNode = st.top();
            st.pop();

            TreeNode* node = nextNode->right;

            while (node){
                st.push(node);
                node = node->left;
            }

            return nextNode->data;
		}
};