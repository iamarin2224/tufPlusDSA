#include <iostream>
using namespace std;

#define mod (int)1e9+7

int countPaths(int n, vector<vector<int>> &roads) {
    vector<pair<int, int>> adj[n];

    for (auto it : roads){
        int u = it[0];
        int v = it[1];
        int edgeWt = it[2];

        adj[u].push_back({v, edgeWt});
        adj[v].push_back({u, edgeWt});
    }

    //Store time-node
    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > pq;

    //Store shortestTime-numWays
    vector<pair<long long, int>> shortestTime(n, {1e18, 0});

    pq.push({0L, 0});
    shortestTime[0] = {0L, 1};

    while (!pq.empty()){
        long long curTime = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        for (auto it: adj[curNode]){
            int adjNode = it.first;
            long long time = (long long)it.second;

            if (curTime + time < shortestTime[adjNode].first){
                shortestTime[adjNode] = {curTime + time, shortestTime[curNode].second};
                pq.push({shortestTime[adjNode].first, adjNode});
            }

            else if (curTime + time == shortestTime[adjNode].first){
                shortestTime[adjNode].second = 
                    ((long long)shortestTime[adjNode].second + (long long)shortestTime[curNode].second)%(mod);
            }
        }
    }

    return shortestTime[n-1].second;
}