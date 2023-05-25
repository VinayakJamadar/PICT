#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e, u, v, w;
    cin >> n >> e;

    vector<pair<int, int>> graph[n];
    for (int i = 0; i < e; i++) {
        cout << "Enter Edge as source, destination and weight" << endl;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<int> h(n);
    cout << "Enter the heuristic value one by one-" << n << endl;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }

    vector<int> f(n, INT_MAX), g(n, INT_MAX), parent(n, -1);

    g[0] = 0;
    f[0] = g[0] + h[0];

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({f[0], 0});

    int node, child, weight;
    
    while (!pq.empty()) {
        node = pq.top().second;
        pq.pop();
        
        for (auto i : graph[node]) {
            child = i.first;
            weight = i.second;

            if(g[node] + weight + h[child] < f[child]) {
                g[child] = g[node] + weight;
                f[child] = g[child] + h[child];
                pq.push({f[child], child});
                parent[child] = node;
            }
        }
    }

    vector<int> path;
    int dest = n-1;
    while (dest != -1) {
        path.push_back(dest);
        dest = parent[dest];
    }
    reverse(path.begin(), path.end());
    cout << "Path is [ ";
    for (auto c : path) {
        cout << c << " ";
    }
    cout << "]";
}