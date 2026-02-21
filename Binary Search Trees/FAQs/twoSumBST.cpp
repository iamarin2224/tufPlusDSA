#include <iostream>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

// Brute

void inorderHelper(TreeNode* root, vector<int>& inorder){
    if (!root){
        return;
    }

    inorderHelper(root->left, inorder);
    inorder.push_back(root->data);
    inorderHelper(root->right, inorder);
}

bool twoSumBST(TreeNode* root, int k){
    vector<int> inorder;
    inorderHelper(root, inorder);

    int left = 0;
    int right = inorder.size()-1;

    while (left < right){
        int current = inorder[left] + inorder[right];

        if (current < k) left++;
        else if (current > k) right--;
        else return true;
    }

    return false;
}

// Optimal (Using BST Iterator)
class BSTIterator{
    stack<TreeNode*> st;
    bool reverse; 
    //if reverse->true then we get reverse inorder, doing next we get the element just before it
    //reverse is done by putting all right then coming to left and all right of left

    void pushAll(TreeNode* root){
        while (root){
            st.push(root);
            if (!reverse) root = root->left;
            else root = root->right;
        }
    }

	public:
		BSTIterator(TreeNode* root, bool reverse){
            this->reverse = reverse;
            pushAll(root);
		}
		
		bool hasNext(){
            return !st.empty();
		}
		
		int next(){
            TreeNode* tempNode = st.top();
            st.pop();

            reverse ? pushAll(tempNode->left) : pushAll(tempNode->right);

            return tempNode->data;
		}
};

bool twoSumBST(TreeNode* root, int k){
    if (!root){
        return false;
    }

    BSTIterator l(root, false); //normal inorder gives the next
    BSTIterator r(root, true); //reverse inorder (desc) ,on doing next actually gives the prev (before)

    int i = l.next();
    int j = r.next();

    while (i < j){
        if (i+j > k) j = r.next(); //moving j to left, to lesser value
        else if (i+j < k) i = l.next(); //moving to next higher value
        else return true;
    }

    return false;
}