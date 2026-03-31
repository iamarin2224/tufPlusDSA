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

        return parent[node] = findUlParent(parent[node]);   //(path compression)
        //this expr results to ulparent and assigns it to parent array
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

        if (ulp_u == ulp_v) return; //as both connected, no need of union

        if (rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;  //similar to connecting u to v
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
