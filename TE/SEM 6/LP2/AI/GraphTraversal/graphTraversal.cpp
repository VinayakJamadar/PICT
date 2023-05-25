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

    void Display() {
        for(int i = 0; i < adjList.size(); i++) {
            cout << i << " -> [ ";
            for(int j = 0; j < adjList[i].size(); j++) {
                cout << adjList[i][j] << " ";
            }
            cout << "]" << endl;
        }
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
        vector<bool> visited(v, 0);
        queue<int> q;
        cout<<"\n1.Display graph."<<endl;
        cout<<"2.Depth First Search."<<endl;
        cout<<"3.Breath First Search."<<endl;
        cout<<"4.Exit."<<endl;
        cout<<"\nEnter the Choice - ";
        cin>>ch;
        if(ch == 1) {
            cout << "\nDisplay graph : " << endl;
            g.Display();
        }
        else if(ch == 2) {
            cout<<"\nDepth First Search : [";
            for (int i = 0; i < v; i++) {
                if (visited[i] == false) {
                    g.DFS(g, i, visited);
                }
            }
            cout << "]";
        }
        else if(ch == 3) {
            cout<<"\nBreath First Search : [ ";
            for (int i = 0; i < v; i++) {
                if (visited[i] == false)
                {
                    visited[i] = true;
                    q.push(i);
                    g.recursiveBFS(g, q, visited);
                }
            }
            cout << "]";
        }
        else if (ch == 4) {
            cout << "Exit.";
        }
        else {
            cout << "Enter a Valid Input";
        }
        cout << endl;
    }
    return 0;
}
