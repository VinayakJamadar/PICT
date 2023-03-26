#include <bits/stdc++.h>

using namespace std;
struct Edge {
    int src, dest;
};
class Graph{
    public:

    vector<vector<int>> adjList;
    //Parametrize Constructor
    Graph(vector<Edge> const &edges, int n)
    {
        adjList.resize(n);
        for (auto &edge: edges)
        {
            adjList[edge.src].push_back(edge.dest);
            adjList[edge.dest].push_back(edge.src);
        }
    }
    
    void DFS(Graph const &graph, int v, vector<bool> &visited)
    {
        visited[v] = true;
        cout << v << " ";
        for (int u: graph.adjList[v])
        {
            if (!visited[u]){
                DFS(graph, u, visited);
            }
        }
    }
    void recursiveBFS(Graph const &graph, queue<int> &q, vector<bool> &visited)
    {
        if (q.empty()) {
            return;
        }
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (int u: graph.adjList[v])
        {
            if (!visited[u])
            {
                visited[u] = true;
                q.push(u);
            }
        }
        recursiveBFS(graph, q, visited);
    }
};

int main(){
    int ch;
    int v,e;
    cout<<"\nEnter the Number of Vertex - ";
    cin>>v;
    cout<<"\nEnter the Number of Edges - ";
    cin>>e;


    vector<Edge> edges;
    vector<bool> visited(v);
    queue<int> q;


    cout<<"\nThe Edges must be from 0 to "<<v-1<<endl;
    for(int i=0;i<e;i++){
        cout<<"Enter the edge(v1 to v2) "<<i+1<<" - ";
        int x,y;
        cin>>x>>y;
        edges.push_back({x,y});
    }
    Graph g(edges,v);
    cout<<"\nGraph Created Successfully!"<<endl;
    while(1){
        cout<<"\n1.Show Graph representation - ";
        cout<<"\n2.Depth First Search - "<<endl;
        cout<<"3.Breath First Search - "<<endl;
        cout<<"\nEnter the Choice - ";
        cin>>ch;
        switch(ch){
            case 1:
                // g.display();
                break;
            case 2:
                for (int i = 0; i < v; i++)
                {
                    if (visited[i] == false) {
                        g.DFS(g, i, visited);
                    }
                }
                break;
            case 3:
                for(int i=0;i<visited.size();i++){
                    visited[i]=false;
                }
                for (int i = 0; i < v; i++)
                {
                    if (visited[i] == false)
                    {
                        visited[i] = true;
                        q.push(i);
                        g.recursiveBFS(g, q, visited);
                    }
                }
                break;
            default:
                break;

        }
    }
    return 0;
}