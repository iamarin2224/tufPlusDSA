#include <iostream>
#include <unordered_set>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

vector<int> distanceK(TreeNode* root, TreeNode* target, int k){
    //Step1: Have a parentMap
    unordered_map<TreeNode*, TreeNode*> parentMap;
    queue<TreeNode*> q; //queue for level order traversal
    q.push(root);
    while (!q.empty()){
        TreeNode* node = q.front();
        q.pop();

        if (node->left){
            parentMap[node->left] = node;
            q.push(node->left);
        }
        if (node->right){
            parentMap[node->right] = node;
            q.push(node->right);
        }
    }

    //Step2: Actual traversal from target
    vector<int> result; 
    unordered_set<TreeNode*> visited;   //to prevent visiting a node twice
    q.push(target);
    visited.insert(target);
    int currentDist = 0;

    while (!q.empty()){
        //If curdist = required, all the elements of queue is the ans
        if (currentDist == k){
            while(!q.empty()){
                result.push_back(q.front()->data);
                q.pop();
            }

            return result;
        }

        int size = q.size();
        
        for (int i=0; i<size; i++){
            TreeNode* node = q.front();
            q.pop();

            //radially search in 3 direcn, while not visiting already visited
            if (node->left && visited.find(node->left) == visited.end()){
                visited.insert(node->left);
                q.push(node->left);
            }
            if (node->right && visited.find(node->right) == visited.end()){
                visited.insert(node->right);
                q.push(node->right);
            }
            if (parentMap.find(node) != parentMap.end() && visited.find(parentMap[node]) == visited.end()){
                visited.insert(parentMap[node]);
                q.push(parentMap[node]);
            }
        }

        currentDist++; //increase the dist after each level of traversal
    }

    return result;
}