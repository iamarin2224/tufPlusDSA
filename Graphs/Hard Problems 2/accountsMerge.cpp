#include <iostream>
using namespace std;

class DisjointSet {
    vector<int> rank;
    vector<int> size;
    vector<int> parent;

public:
    DisjointSet(int n) {
        rank.resize(n, 0);
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

vector<vector<string>> accountsMerge(vector<vector<string>> accounts){
    int n = accounts.size();

    DisjointSet ds(n);
    unordered_map<string, int> mapMailNode;

    for (int i=0; i<n; i++){
        for (int j=1; j<accounts[i].size(); j++){
            string mail = accounts[i][j];

            if (mapMailNode.find(mail) == mapMailNode.end()){
                mapMailNode[mail] = i;
            }
            else{
                ds.unionBySize(i, mapMailNode[mail]);
            }
        }
    }

    vector<vector<string>> mergedMail(n);
    for (auto it: mapMailNode){
        string mail = it.first;
        int node = ds.findUlParent(it.second);

        mergedMail[node].push_back(mail);
    }

    vector<vector<string>> ans;
    for (int i=0; i<n; i++){
        if (mergedMail[i].size() == 0) continue;

        vector<string> temp;
        temp.push_back(accounts[i][0]);

        sort(mergedMail[i].begin(), mergedMail[i].end());
        for (string mail: mergedMail[i]){
            temp.push_back(mail);
        }

        ans.push_back(temp);
    }

    return ans;
}