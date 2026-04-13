#include <iostream>
using namespace std;

void dfs(int node, int parent, vector<int> adj[], vector<bool> &vis, 
        vector<int> &tin, vector<int> &low, vector<int> &mark, int &timer)
{
    vis[node] = true;

    tin[node] = low[node] = timer;
    timer++;

    int child = 0;

    for (int adjNode: adj[node]){
        if (adjNode == parent) continue;

        if (!vis[adjNode]){
            dfs(adjNode, node, adj, vis, tin, low, mark, timer);

            low[node] = min(low[node], low[adjNode]);

            if (tin[node] <= low[adjNode] && parent != -1){
                mark[node] = 1;
            }

            child++;
        }
        else{
            low[node] = min(low[node], tin[adjNode]);
        }
    }

    if (child > 1 && parent == -1) mark[node] = 1;
}

vector<int> articulationPoints(int n, vector<int>adj[]) {
    vector<bool> vis(n, false);    

    vector<int> tin(n);
    vector<int> low(n);

    vector<int> mark(n, 0);
    int timer = 0;

    for (int i=0; i<n; i++){
        if (!vis[i])
            dfs(i, -1, adj, vis, tin, low, mark, timer);
    }

    vector<int> ans;
    for (int i=0; i<n; i++){
        if (mark[i] == 1) ans.push_back(i);
    }

    if (ans.size() == 0) return {-1};

    return ans;
}