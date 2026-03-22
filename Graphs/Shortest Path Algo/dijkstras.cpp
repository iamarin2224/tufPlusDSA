#include <iostream>
#include <set>
using namespace std;

//? Priority Queue Way

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    //Implement min-heap in cpp, stores dist-node
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    //Dist array with all as inifnity
    vector<int> dist(V, 1e9);

    //Source at dist zero
    dist[S] = 0;
    pq.push({0, S});

    while (!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]){
            int adjNode = it[0];
            int edgeWt = it[1];

            //Relaxation of edges
            if (dis + edgeWt < dist[adjNode]){
                dist[adjNode] = dis + edgeWt;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}

//? Set Way

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    //Set that stores dist-node
    set<pair<int, int>> st;

    //Dist array with all as inifnity
    vector<int> dist(V, 1e9);

    //Source at dist zero
    dist[S] = 0;
    st.insert({0, S});

    while (!st.empty()){
        int dis = st.begin()->first;
        int node = st.begin()->second;
        st.erase(st.begin());

        for (auto it : adj[node]){
            int adjNode = it[0];
            int edgeWt = it[1];

            //Relaxation of edges
            if (dis + edgeWt < dist[adjNode]){

                if (dist[adjNode] != 1e9) st.erase({dist[adjNode], adjNode});

                dist[adjNode] = dis + edgeWt;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }

    return dist;
}