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

    int getSize(int node){
        return size[node];
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

int largestIsland(vector<vector<int>>& grid) {
    int n = grid.size();

    DisjointSet ds(n*n);

    int rows[4] = {0, 0, 1, -1};
    int cols[4] = {1, -1, 0, 0};

    //Add initial islands into DS
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){

            if (grid[i][j] == 0) continue;

            for (int k=0; k<4; k++){
                int nRow = i+rows[k];
                int nCol = j+cols[k];

                if (
                    nRow>=0 && nRow<n &&
                    nCol>=0 && nCol<n &&
                    grid[nRow][nCol] == 1
                ){
                    if (!ds.find(i*n+j, nRow*n+nCol)){
                        ds.unionBySize(i*n+j, nRow*n+nCol);
                    }
                }
            }
        }
    }

    int maxSize = 0;

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){

            if (grid[i][j] == 0){
                int curSize = 1;

                unordered_set<int> st; //Use set to avoid duplicates

                for (int k=0; k<4; k++){
                    int nRow = i+rows[k];
                    int nCol = j+cols[k];
    
                    if (
                        nRow>=0 && nRow<n &&
                        nCol>=0 && nCol<n &&
                        grid[nRow][nCol] == 1
                    ){
                        //Add ultimate parents to avoid duplicates
                        st.insert(ds.findUlParent(nRow*n+nCol));
                    }
                }

                //Iterate over set to get the cursize
                for (int it: st){
                    curSize += ds.getSize(it);
                }

                maxSize = max(maxSize, curSize);
            }
        }
    }
    
    //Edge case of all cell = 1
    if (maxSize == 0) return n*n;

    return maxSize;
}