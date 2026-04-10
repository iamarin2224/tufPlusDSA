#include <iostream>
#include <unordered_set>
using namespace std;

class DisjointSet {
    vector<int> size;
    vector<int> parent;

public:
    DisjointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    int findUlParent(int node){
        if (node == parent[node]){
            return node;
        }

        return parent[node] = findUlParent(parent[node]);   
    }

    bool find(int u, int v) {
        return findUlParent(u) == findUlParent(v);
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

class Solution {
public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxRows = 0;
        int maxCols = 0;

        for (auto it: stones){
            maxRows = max(maxRows, it[0]);
            maxCols = max(maxCols, it[1]);
        }

        DisjointSet ds(maxRows+maxCols+2);

        unordered_set<int> stoneNodes;

        for (auto it: stones){
            int nodeRow = it[0];
            int nodeCol = maxRows + it[1] + 1;
            
            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes.insert(nodeRow);
            stoneNodes.insert(nodeCol);
        }

        int numConnected = 0;

        for (int it: stoneNodes){
            if (ds.findUlParent(it) == it) numConnected++;
        }

        return n-numConnected;
    }
};