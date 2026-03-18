#include <iostream>
#include <unordered_set>
using namespace std;

//? DFS Way

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

bool isCyclic(int N, vector<int> adj[]) {
    vector<bool> vis(N, false);

    vector<bool> pathVisited(N, false);

    for (int i=0; i<N; i++){
        if (!vis[i]){
            if (dfs(i, vis, adj, pathVisited)) return true;
        }
    }

    return false;
}

//? BFS Way

bool isCyclic(int N, vector<int> adj[]) {
    vector<int> indegree(N, 0);
    
    for (int i=0; i<N; i++){
        for (auto it : adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;

    for (int i=0; i<N; i++){
        if (indegree[i] == 0){
            q.push(i);
        }
    }

    int cnt = 0;

    while (!q.empty()){
        int node = q.front();
        q.pop();
        cnt++;

        for (auto it : adj[node]){
            indegree[it]--;
            if (indegree[it] == 0) q.push(it);
        }
    }

    if (cnt == N) return false;
    return true;
}