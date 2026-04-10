#include <iostream>
using namespace std;

//? BFS Way

bool detectBFS(int src, vector<bool>& vis, vector<int> adj[]){
    vis[src] = true;

    //stores node-parent pair
    queue<pair<int, int>> q;

    q.push({src, -1});

    while (!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (int adjNode : adj[node]){
            if (!vis[adjNode]){
                vis[adjNode] = true;
                q.push({adjNode, node});
            }
            else if (adjNode != parent){
                return true;
            }
        }
    }

    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<bool> vis(V, false);

    for (int i=0; i<V; i++){
        if (!vis[i]){
            if (detectBFS(i, vis, adj)){
                return true;
            }
        }
    }

    return false;
}  

//? DFS Way

bool detectDFS(int node, vector<bool>& vis, vector<int> adj[], int parent){
    vis[node] = true;

    for (int adjNode : adj[node]){
        if (!vis[adjNode]){
            if (detectDFS(adjNode, vis, adj, node)) return true;
        }
        else if (adjNode != parent) return false;
    }

    return false;
}

bool isCycle(int V, vector<int> adj[]) {
    vector<bool> vis(V, false);

    for (int i=0; i<V; i++){
        if (!vis[i]){
            if (detectDFS(i, vis, adj, -1)){
                return true;
            }
        }
    }

    return false;
}
