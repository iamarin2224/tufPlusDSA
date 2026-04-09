#include <iostream>
using namespace std;

#define p pair<int, int>

class DisjointSet {
    vector<vector<int>> size;
    vector<vector<pair<int, int>>> parent;
    
    public:
    DisjointSet(int n, int m) {
        size.resize(n, vector<int>(m, 1));
        parent.resize(n, vector<pair<int,int>>(m, {0, 0}));
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                parent[i][j] = {i, j};
            }
        }
    }
    
    p findUlParent(p node){
        if (node == parent[node.first][node.second]){
            return node;
        }

        return parent[node.first][node.second] = findUlParent(parent[node.first][node.second]);   
    }

    bool find(p u, p v) {
        return findUlParent(u) == findUlParent(v);
    }

    void unionBySize(p u, p v) {
        p ulp_u = findUlParent(u);
        p ulp_v = findUlParent(v);

        if (ulp_u == ulp_v) return; 

        if (size[ulp_u.first][ulp_u.second] < size[ulp_v.first][ulp_v.second]){
            parent[ulp_u.first][ulp_u.second]  = ulp_v;  
            size[ulp_v.first][ulp_v.second]  += size[ulp_u.first][ulp_u.second] ;
        }
        else{
            parent[ulp_v.first][ulp_v.second]= ulp_u;
            size[ulp_u.first][ulp_u.second] += size[ulp_v.first][ulp_v.second];
        }
    }

    int numConnectedComponents(){
        int cnt = 0;

        for (int i=0; i<parent.size(); i++){
            for (int j=0; j<parent[0].size(); j++){
                if (parent[i][j] == pair<int,int>{i, j}) cnt++;
            }
        }

        return cnt;
    }
};

vector<int> numOfIslands(int n, int m, vector<vector<int>> &A){
    vector<vector<int>> mat(n, vector<int>(m, 0));

    vector<int> ans;
    int cnt = 0;

    vector<int> rows = {0, 0, 1, -1};
    vector<int> cols = {1, -1, 0, 0};

    DisjointSet ds(n, m);

    for (int i=0; i<A.size(); i++){
        int row = A[i][0];
        int col = A[i][1];

        if (mat[row][col] == 1){
            ans.push_back(cnt);
            continue;
        }

        mat[row][col] = 1;

        cnt++;

        for (int j=0; j<4; j++){
            int nRow = row + rows[j];
            int nCol = col + cols[j];

            if (
                nRow >=0 && nRow < n &&
                nCol >=0 && nCol < m &&
                mat[nRow][nCol] == 1
            ){
                if (!ds.find({row, col}, {nRow, nCol})){
                    cnt--;
                    ds.unionBySize({row, col}, {nRow, nCol});
                }
            }
        }

        ans.push_back(cnt);
    }

    return ans;
}