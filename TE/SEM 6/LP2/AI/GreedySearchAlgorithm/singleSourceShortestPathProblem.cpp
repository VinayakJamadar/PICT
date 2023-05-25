#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter the Number of Vertex - ";
    cin >> n;
    vector<pair<int, int>> adj[n];
    int e;
    cout << "Enter the Number of edges - ";
    cin >> e;

    int u, v, w;
    for (int i = 0; i < e; i++) {
        cout << "Enter Edge as source, destination and weight" << endl;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<int> distTo(n, INT_MAX);
    vector<int> parent(n, -1);

    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    
    distTo[0] = 0;
    pq.push({0, 0});
    
    int dist, node, child, weight;
    while(!pq.empty()) {
        dist = pq.top().first;
        node = pq.top().second;
        pq.pop();

        for(auto i: adj[node]) {
            child = i.first;
            weight = i.second;

            if(dist + weight < distTo[child]) {
                distTo[child] = dist + weight;
                parent[child] = node;
                pq.push({dist + weight, child});
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        vector<int> path;
        int dst = i;
        while(dst != -1) {
            path.push_back(dst);
            dst = parent[dst];
        }
        reverse(path.begin(), path.end());

        cout << "Shortest Distance for node " << i << " from node 0 is with distance : " << distTo[i] << endl;
        cout << "Shortest Path for node " << i << " from node 0 is : [ ";
        for (int i = 0; i < path.size(); i++) {
            cout << path[i] << " ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}