#include <iostream>
using namespace std;

//? DFS

bool dfs(int node, vector<bool>& vis, vector<int> adj[], vector<bool>& pathVisited, vector<bool>& check){
    vis[node] = true;

    pathVisited[node] = true;

    check[node] = false;

    for (int adjNode: adj[node]){
        if (!vis[adjNode]){
            if (dfs(adjNode, vis, adj, pathVisited, check)) return true;
        }
        else if (pathVisited[adjNode]) {
            return true;
        }
    }

    pathVisited[node] = false;

    check[node] = true;

    return false;
}

vector<int> eventualSafeNodes(int V, vector<int> adj[]){
    vector<bool> vis(V, false);

    vector<bool> pathVisited(V, false);

    vector<bool> check(V, false);

    for (int i=0; i<V; i++){
        if (!vis[i]){
            dfs(i, vis, adj, pathVisited, check);
        }
    }

    vector<int> ans;

    for (int i=0; i<V; i++){
        if (check[i]){
            ans.push_back(i);
        }
    }

    return ans;
}

//? BFS

vector<int> eventualSafeNodes(int V, vector<int> adj[]){
    vector<int> adjRev[V];

    vector<int> indegree(V, 0);

    for (int i=0; i<V; i++){
        for (int it : adj[i]){
            adjRev[it].push_back(i);
            indegree[i]++;
        }
    }

    queue<int> q;

    for (int i=0; i<V; i++){
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> safeNodes;

    while (!q.empty()){
        int node = q.front();
        q.pop();
        safeNodes.push_back(node);

        for (int it : adjRev[node]){
            indegree[it]--;
            if (indegree[it] == 0) q.push(it);
        }
    }

    sort(safeNodes.begin(), safeNodes.end());

    return safeNodes;
}