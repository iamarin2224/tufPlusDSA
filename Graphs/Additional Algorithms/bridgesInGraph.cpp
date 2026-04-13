#include <iostream>
using namespace std;

void dfs(int node, int parent, vector<int> adj[], vector<bool> &vis, 
        vector<int> &tin, vector<int> &low, vector<vector<int>> &bridges, int &timer)
{
    vis[node] = true;

    tin[node] = low[node] = timer;
    timer++;

    for (int adjNode: adj[node]){
        if (adjNode == parent) continue;

        if (!vis[adjNode]){
            dfs(adjNode, node, adj, vis, tin, low, bridges, timer);

            low[node] = min(low[node], low[adjNode]);

            if (tin[node] < low[adjNode]){
                bridges.push_back({node, adjNode});
            }
        }
        else{
            low[node] = min(low[node], tin[adjNode]);
        }
    }
}

vector<vector<int>> criticalConnections(int V, vector<vector<int>>& E) {
    vector<int> adj[V];

    for (auto it: E){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<bool> vis(V, false);

    vector<int> tin(V);
    vector<int> low(V);

    vector<vector<int>> bridges;

    int timer = 0;

    dfs(0, -1, adj, vis, tin, low, bridges, timer);

    return bridges;
}