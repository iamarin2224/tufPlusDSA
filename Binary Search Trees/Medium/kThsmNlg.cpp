#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

//Brute- TC:O(N) SC:O(2*N)
void inorderFn(TreeNode* root, vector<int>& ans){
    if (root == nullptr){
        return;
    }

    inorderFn(root->left, ans);
    ans.push_back(root->data);
    inorderFn(root->right, ans);
}

vector<int> kLargesSmall(TreeNode* root,int k){
    vector<int> inorder;
    inorderFn(root, inorder);

    int n = inorder.size();

    return {inorder[k-1], inorder[n-k]};
}

//Optimal- TC:O(N) SC:O(N)
void kthLargest(TreeNode* root, int& cnt, int& largest){
    if (root == nullptr){
        return;
    }

    kthLargest(root->right, cnt, largest);
    if (--cnt == 0) {
        largest = root->data;
        return;
    }
    kthLargest(root->left, cnt, largest);
}

void kThSmallest(TreeNode* root, int& cnt, int& smallest){
    if (root == nullptr){
        return;
    }

    kThSmallest(root->left, cnt, smallest);
    if (--cnt == 0) {
        smallest = root->data;
        return;
    }
    kThSmallest(root->right, cnt, smallest);
}

vector<int> kLargesSmall(TreeNode* root,int k){
    int cntSm = k, cntLg = k;
    int largest, smallest;

    kthLargest(root, cntLg, largest);
    kThSmallest(root, cntSm, smallest);

    return {smallest, largest};
}