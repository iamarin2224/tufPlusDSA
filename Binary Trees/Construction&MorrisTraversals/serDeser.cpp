#include <iostream>
#include <sstream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : data(val) , left(nullptr) , right(nullptr) {}
};

string serialize(TreeNode* root) {
    if (root == nullptr){
        return "";
    }   

    stringstream ss;

    queue<TreeNode*> q;

    q.push(root);

    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();

        if (node == nullptr){
            ss << "#,";
        }
        else{
            ss << node->data << ",";

            q.push(node->left);
            q.push(node->right);
        }
    }

    return ss.str();
}

TreeNode* deserialize(string data) {
    if (data.empty()){
        return nullptr;
    }

    stringstream s(data); //Tokenize the given string
    string str; //Temp string for storing nodes

    getline(s, str, ','); //gives the data with `,`

    TreeNode* root = new TreeNode(stoi(str));
    
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()){
        TreeNode* node = q.front();
        q.pop();

        getline(s, str, ','); //read value of left child
        if (str != "#") {
            TreeNode* leftNode = new TreeNode(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }
        
        getline(s, str, ',');   //read value of right child
        if (str != "#") {
            TreeNode* rightNode = new TreeNode(stoi(str));
            node->right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
}