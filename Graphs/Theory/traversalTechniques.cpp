#include <iostream>
using namespace std;

void dfsUtil(int node, vector<int> adj[], vector<int>& vis, vector<int>& ans){
    vis[node] = 1;
    ans.push_back(node);

    for (auto it: adj[node]){
        if (!vis[it]){
            dfsUtil(it, adj, vis, ans);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    vector<int> ans;

    int start = 0;

    dfsUtil(start, adj, vis, ans);

    return ans;
}

vector<int> bfsOfGraph(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    queue<int> q;

    vis[0] = 1;
    q.push(0);

    vector<int> bfs;

    while(!q.empty()){
        int node = q.front();
        q.pop();

        bfs.push_back(node);

        for (auto it: adj[node]){
            if (!vis[it]){
                vis[it] = 1;
                q.push(it);
            }
        }
    }

    return bfs;
}