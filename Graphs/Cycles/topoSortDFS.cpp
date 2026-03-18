#include <iostream>
using namespace std;

void dfs(int i, vector<bool>& vis, stack<int>& st, vector<int> adj[]){
    vis[i] = true;

    for (int adjNode : adj[i]){
        if (!vis[adjNode]){
            dfs(adjNode, vis, st, adj);
        }
    }

    st.push(i);
}

vector<int> topoSort(int V, vector<int> adj[]){
    vector<bool> vis(V, false);
    
    stack<int> st;

    for (int i=0; i<V; i++){
        if (!vis[i]) dfs(i, vis, st, adj);
    }

    vector<int> ans;

    while (!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}