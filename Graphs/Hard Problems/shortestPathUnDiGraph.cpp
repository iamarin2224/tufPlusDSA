#include <iostream>
using namespace std;

vector<int> shortestPath(vector<vector<int>>& edges, int N, int M){
    vector<int> adj[N];

    for (auto it : edges){  
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    int src = 0;

    vector<int> dist(N, 1e9);
    
    queue<int> q;
    
    q.push(src);
    dist[src] = 0;

    // vector<bool> vis(N, false);
    // vis[src] = true;

    while (!q.empty()){
        int node = q.front();
        q.pop();

        for (int adjNode : adj[node]){
            if (dist[adjNode] > dist[node] + 1){
                dist[adjNode] = dist[node] + 1;
                q.push(adjNode);
            }
            // if (!vis[adjNode]) {
            //     vis[adjNode] = true;
            //     dist[adjNode] = dist[node] + 1;
            //     q.push(adjNode);
            // }
        }

        
    }

    for (int i=0; i<N; i++){
        if (dist[i] == 1e9) dist[i] = -1;
    }

    return dist;
}