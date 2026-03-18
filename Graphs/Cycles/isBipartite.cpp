#include <iostream>
using namespace std;

bool dfs(int node, vector<bool>& vis, vector<int> adj[], vector<int>& col){
    vis[node] = true;

    for (int adjNode : adj[node]){
        if (!vis[adjNode]){
            col[adjNode] = !col[node];
            if (dfs(adjNode, vis, adj, col) == false) return false;
        }
        else if (col[adjNode] == col[node]) return false;
    }

    return true;
}

bool isBipartite(int V, vector<int> adj[]){
    vector<bool> vis(V, false);

    vector<int> col(V);

    for (int i=0; i<V; i++){
        if (!vis[i]){
            col[i] = 0;
            if (dfs(i, vis, adj, col) == false) return false;
        }
    }

    return true;
}