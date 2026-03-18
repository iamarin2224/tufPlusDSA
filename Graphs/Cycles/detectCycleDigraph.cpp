#include <iostream>
#include <unordered_set>
using namespace std;

//? DFS Way

bool dfs(int node, vector<bool>& vis, vector<int> adj[], vector<bool>& completed){
    vis[node] = true;

    for (int adjNode: adj[node]){
        if (!vis[adjNode]){
            if (dfs(adjNode, vis, adj, completed)) return true;
        }
        else if (!completed[adjNode]) {
            return true;
        }
    }

    completed[node] = true;

    return false;
}

bool isCyclic(int N, vector<int> adj[]) {
    vector<bool> vis(N, false);

    vector<bool> completed(N, false);

    for (int i=0; i<N; i++){
        if (!vis[i]){
            if (dfs(i, vis, adj, completed)) return true;
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