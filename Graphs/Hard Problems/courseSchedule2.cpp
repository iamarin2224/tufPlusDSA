#include <iostream>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    int N = numCourses;

    vector<int> adjRev[N];

    vector<int> indegree(N, 0);
    
    for (auto it : prerequisites){
        adjRev[it[1]].push_back(it[0]);
        indegree[it[0]]++;
    }

    queue<int> q;

    for (int i=0; i<N; i++){
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> ans;

    while (!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for (int i : adjRev[node]){
            indegree[i]--;
            if (indegree[i] == 0) q.push(i);
        }
    }

    if (ans.size() < N) return {};
    
    return ans;
}