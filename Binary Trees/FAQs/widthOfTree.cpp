#include <iostream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

#define ull unsigned long long

long long widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0L;

    ull maxWidth = 0ULL;

    // Queue stores node-index pair
    queue<pair<TreeNode*, ull>> q;
    q.push({root, 0L});

    while (!q.empty()){
        ull size = q.size();

        ull firstIdx, lastIdx;

        for (ull i=0; i<size; i++){
            auto p = q.front();
            q.pop();

            TreeNode* node = p.first;
            ull index = p.second;
            if (i==0) firstIdx = index;
            if (i==size-1) lastIdx = index;

            if (node->left){
                q.push({node->left, 2ULL*index});
            }
            if (node->right){
                q.push({node->right, 2ULL*index+1ULL});
            }
        }

        maxWidth = max(maxWidth, lastIdx-firstIdx+1ULL);
    }

    return maxWidth;
}