#include <iostream>
using namespace std;

//? Krushkal Algorithm

class DisjointSet {
    vector<int> rank;
    vector<int> size;
    vector<int> parent;

    int findUlParent(int node){
        if (node == parent[node]){
            return node;
        }

        return parent[node] = findUlParent(parent[node]);   
    }

public:
    DisjointSet(int n) {
        rank.resize(n, 0);
        size.resize(n, 1);
        parent.resize(n);
        for (int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    bool find(int u, int v) {
        return findUlParent(u) == findUlParent(v);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUlParent(u);
        int ulp_v = findUlParent(v);

        if (ulp_u == ulp_v) return; 

        if (rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v; 
        }

        else if (rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }

        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUlParent(u);
        int ulp_v = findUlParent(v);

        if (ulp_u == ulp_v) return; 

        if (size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;  
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int spanningTree(int V, vector<vector<int>> adj[]) {
    vector<pair<int, pair<int, int>>> edges;

    for (int i=0; i<V; i++){
        for (auto it: adj[i]){
            int node = i;
            int adjNode = it[0];
            int wt = it[1];

            edges.push_back({wt, {node, adjNode}});
        }
    }

    sort(edges.begin(), edges.end());

    DisjointSet ds(V);

    int mstWt = 0;

    for (auto it: edges){
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if (!ds.find(u, v)){
            mstWt += wt;
            ds.unionBySize(u, v);
        }
    }

    return mstWt;
}

//? Prims Algorithm

int spanningTree(int V, vector<vector<int>> adj[]) {
    //As we only require the total min wt of mst, and not the edges involved in the mst, we only store <wt-node> pair, if we required to find edges in mst we would use <wt-node-parent>

    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    vector<int> vis(V, 0);

    pq.push({0, 0});

    int sum = 0;

    while (!pq.empty()){
        int node = pq.top().second;
        int wt = pq.top().first;
        pq.pop();

        if (vis[node]) continue;    //Skip if node visited

        //Mark it as visited after popping it out, and add the edge wt to sum
        vis[node] = 1;
        sum += wt;

        //Traverse the adjNodes and add to pq if unvisited
        for (auto it: adj[node]){
            int adjNode = it[0];
            int adjWt = it[1];

            if (!vis[adjNode]){
                pq.push({adjWt, adjNode});
            }
        }
    }

    return sum;
}