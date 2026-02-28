#include <iostream>
using namespace std;

void dfsUtil(int node, vector<int> adj[], vector<int>& vis){
    vis[node] = 1;

    for (auto it: adj[node]){
        if (!vis[it]){
            dfsUtil(it, adj, vis);
        }
    }
}

int findNumberOfComponent(int V, vector<vector<int>> &edges) {
    vector<int> adj[V];

    for (auto it: edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> vis(V, 0);
    int count = 0;

    for(int i=0; i<V; i++){
        if (!vis[i]){
            count++;
            dfsUtil(i, adj, vis);
        }
    }

    return count;
}