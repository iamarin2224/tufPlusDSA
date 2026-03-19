#include <iostream>
using namespace std;

void dfs(int node, vector<bool>& vis, vector<pair<int, int>> adj[], stack<int>& st){
    vis[node] = true;

    for (auto it : adj[node]){
        if (!vis[it.first]){
            dfs(it.first, vis, adj, st);
        }
    }

    st.push(node);
}

vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
    vector<pair<int, int>> adj[V];  
    
    int src = 0;

    for (auto it : edges){
        adj[it[0]].push_back({it[1], it[2]});
    }

    vector<bool> vis(V, false);
    stack<int> st;

    for (int i=0; i<V; i++){
        if (!vis[i]){
            dfs(i, vis, adj, st);
        }
    }

    vector<int> dist(V, 1e9);

    dist[src] = 0;

    while (!st.empty()){
        int node = st.top();
        st.pop();

        if (dist[node] != 1e9){
            for (auto it : adj[node]){
                if (dist[node] + it.second < dist[it.first]){
                    dist[it.first] = dist[node] + it.second;
                }
            }
        }
    }

    for (int i=0; i<V; i++){
        if (dist[i] == 1e9){
            dist[i] = -1;
        }
    }

    return dist;
}