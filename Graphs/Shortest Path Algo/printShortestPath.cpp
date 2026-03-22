#include <iostream>
using namespace std;

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {
    vector<pair<int, int>> adj[n+1];

    for (int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    priority_queue<
        vector<int>,
        vector<vector<int>>,
        greater<vector<int>>
    > pq;

    vector<int> dist(n+1, 1e9);

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()){
        vector<int> curPath = pq.top();

        int dis = curPath[0];
        int node = curPath.back();

        if (node == n) return curPath;

        pq.pop();

        for (auto it : adj[node]){
            int adjNode = it.first;
            int edgeWt = it.second;

            if (dis + edgeWt < dist[adjNode]){
                dist[adjNode] = dis + edgeWt;
                curPath[0] = dist[adjNode];
                curPath.push_back(adjNode);
                pq.push(curPath);
                curPath[0] = dis;
                curPath.pop_back();
            }
        }
    }

    return {-1};
}

//? TUF way of using a parent array and rebuilding from that

vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {
    vector<pair<int, int>> adj[n+1];

    for (int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    vector<int> dist(n+1, 1e9);

    vector<int> parent(n+1);

    //Everyone is there own parent in start
    for (int i=0; i<n+1; i++){
        parent[i] = i;
    }

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]){
            int adjNode = it.first;
            int edgeWt = it.second;

            if (dis + edgeWt < dist[adjNode]){
                dist[adjNode] = dis + edgeWt;
                pq.push({dist[adjNode], adjNode});
                parent[adjNode] = node;
            }
        }
    }

    if (dist[n] == 1e9) return {-1};

    //Reconstructing the path

    vector<int> path;
    int node = n;

    while (parent[node] != node){
        path.push_back(node);
        node = parent[node];
    }

    path.push_back(1); //Add the source

    reverse(path.begin(), path.end());

    path.insert(path.begin(), dist[n]);

    return path;
}