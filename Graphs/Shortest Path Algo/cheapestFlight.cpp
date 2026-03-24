#include <iostream>
using namespace std;

int CheapestFlight(int n, vector<vector<int>> &flights, int src, int dst, int K) {
    vector<pair<int, int>> adj[n];
    
    for (auto it: flights){
        // u -> v
        int u = it[0];
        int v = it[1];
        int edgeWt = it[2];
        adj[u].push_back({v, edgeWt});
    }

    // stops-price-nodes
    queue<pair<int, pair<int, int>>> q;

    vector<int> price(n, 1e9);

    price[src] = 0;
    q.push({0, {0, src}});

    while (!q.empty()){
        int curStops = q.front().first;
        int curPrice = q.front().second.first;
        int node = q.front().second.second;
        q.pop();

        if (curStops >= K+1) continue;

        for (auto it: adj[node]){
            int adjNode = it.first;
            int edgeWt = it.second;

            if (curPrice+edgeWt < price[adjNode]){
                price[adjNode] = curPrice+edgeWt;
                q.push({curStops+1, {price[adjNode], adjNode}});
            }
        }
    }

    if (price[dst] == 1e9) return -1;

    return price[dst];
}