#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

vector<int> floorCeilOfBST(TreeNode* root,int key){
    vector<int> ans = {-1, -1};

    TreeNode* cur = root;

    while (cur != nullptr){
        if (key == cur->data){
            ans[0] = ans[1] = cur->data;
            break;
        }
        else if (cur->data > key){
            ans[1] = cur->data;
            cur = cur->left;
        }
        else {
            ans[0] = cur->data;
            cur = cur->right;
        }
    }

    return ans;
}