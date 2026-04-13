#include <iostream>
using namespace std;

void dfsWithStack(int node, vector<int> adj[], stack<int> &st, vector<bool> &vis){
    vis[node] = true;

    for (int adjNode: adj[node]){
        if (!vis[adjNode]){
            dfsWithStack(adjNode, adj, st, vis);
        }
    }

    st.push(node);
}

void dfs(int node, vector<int> adj[], vector<bool> &vis){
    vis[node] = true;

    for (int adjNode: adj[node]){
        if (!vis[adjNode]){
            dfs(adjNode, adj, vis);
        }
    }
}

int kosaraju(int V, vector<int> adj[]){
    vector<bool> vis(V, false);
    stack<int> st;

    for (int i=0; i<V; i++){
        if (!vis[i]){
            dfsWithStack(i, adj, st, vis);
        }
    }

    vector<int> adjRev[V];
    for (int i=0; i<V; i++){
        for (int j: adj[i]){
            adjRev[j].push_back(i);
        }
    }

    int sccCount = 0;

    vis.clear();
    vis.resize(V, false);

    while (!st.empty()){
        int node = st.top();
        st.pop();

        if (!vis[node]){
            sccCount++;
            dfs(node, adjRev, vis);
        }
    }

    return sccCount;
}