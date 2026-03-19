#include <iostream>
using namespace std;

bool dfs(int node, vector<bool>& vis, vector<int> adj[], vector<bool>& pathVisited){
    vis[node] = true;

    pathVisited[node] = true;

    for (int adjNode: adj[node]){
        if (!vis[adjNode]){
            if (dfs(adjNode, vis, adj, pathVisited)) return true;
        }
        else if (pathVisited[adjNode]) {
            return true;
        }
    }

    pathVisited[node] = false;

    return false;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    int N = numCourses;

    vector<int> adj[N];
    
    for (auto it : prerequisites){
        adj[it[0]].push_back(it[1]);
    }

    vector<bool> vis(N, false);

    vector<bool> pathVisited(N, false);

    for (int i=0; i<N; i++){
        if (!vis[i]){
            if (dfs(i, vis, adj, pathVisited)) return false;
        }
    }

    return true;
}