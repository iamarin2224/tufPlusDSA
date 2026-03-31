#include <iostream>
using namespace std;

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

    int numConnectedComponents(){
        int cnt = 0;

        for (int i=0; i<parent.size(); i++){
            if (parent[i] == i) cnt++;
        }

        return cnt;
    }
};

int solve(int n, vector<vector<int>> &Edge){
    DisjointSet ds(n);

    int extraEdges = 0;

    for (auto it: Edge){
        int u = it[0];
        int v = it[1];

        if (ds.find(u, v)){
            extraEdges++;
        }
        else{
            ds.unionBySize(u, v);
        }
    }

    int nc = ds.numConnectedComponents();

    if (extraEdges >= nc-1) return nc-1;

    return -1;
}