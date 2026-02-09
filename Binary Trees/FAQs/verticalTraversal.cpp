#include <iostream>
#include <map>
using namespace std;

#define pq priority_queue<int, vector<int>, greater<int>>

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> result;

    if (!root) return result;

    //the main data structure which stores the node corresponding to each row & column 
    //we will use this to construct our result after wards
    //stores as col -> row -> nodes, pq is used as for same row and col we need in sorted order, we use minHeap
    //also map is used as we need to go col by col inside it row by row
    map<int, map<int, pq>> nodeMap;

    //queue stores as {Node, {row, col}}, needed as we will be doing bfs (level-order)
    queue<pair<TreeNode*, pair<int, int>>> q;

    q.push({root, {0, 0}});

    //main bfs traversal
    while (!q.empty()){
        auto p = q.front();
        q.pop();

        TreeNode* node = p.first;
        int row = p.second.first;
        int col = p.second.second;

        nodeMap[col][row].push(node->data);

        if (node->left){
            q.push({node->left, {row+1, col-1}});
        }
        if (node->right){
            q.push({node->right, {row+1, col+1}});
        }
    }

    //x is the `col - {row, pq}` pair
    for (auto& x: nodeMap){
        vector<int> coloumn;

        //y is the `row-pq` pair
        for (auto& y: x.second){
            //loop untill pq is empty
            while (!y.second.empty()){
                coloumn.push_back(y.second.top());
                y.second.pop();
            }
        }

        result.push_back(coloumn);
    }

    return result;
}
