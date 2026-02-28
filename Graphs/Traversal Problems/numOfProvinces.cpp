#include <iostream>
using namespace std;

void dfsUtil(int node, vector<vector<int>>& adj, vector<int>& vis){
    int V = adj.size();

    vis[node] = 1;

    for (int i=0; i<V; i++){
        if (adj[node][i] == 1){
            if (!vis[i]){
                dfsUtil(i, adj, vis);
            }
        }
    }
}

int numProvinces(vector<vector<int>> adj) {
    int V = adj.size();

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