#include <iostream>
using namespace std;

bool isColouringSafe(int node, int col, vector<int> &colour, vector<int> adj[]){
    for (int i=0; i<adj[node].size(); i++){
        if (colour[adj[node][i]] == col){
            return false;
        }
    }
    return true;
}

bool func(int node, int n, int m, vector<int> &colour, vector<int> adj[]){
    if (node == n){
        return true;
    }

    for (int i=1; i<=m; i++){
        if (isColouringSafe(node, i, colour, adj)){
            //is safe to place, place it
            colour[node] = i;
            //go to next node after placing and return directly if true
            if (func(node+1, n, m, colour, adj)) return true;   
            colour[node] = 0;   //backtrack for further exploration
        }
    }

    return false;
}

bool graphColoring(vector<vector<int>> &edges, int m, int n) {
    //array of vectors in which, each index is the node and its value (a vector) is a list of adjacent nodes
    vector<int> adj[n]; 

    for(int i = 0; i<edges.size(); i++){
        //for each element in edges, the 
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }

    vector<int> colour(n, 0);   //list to hold which node is given which colour

    return func(0, n, m, colour, adj);
}