#include <bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, set<int>> adj;

public:
    void insertEdge(int u, int v, bool direction)
    {
        adj[u].insert(v);

        // direction->0 Directed
        // direction->1 UnDirected
        if (direction == 1)
        {
            adj[v].insert(u);
        }
    }
    void printAdjacenyList()
    {
        for (auto it1 : adj)
        {
            cout << it1.first << " -> ";
            for (auto it2 : it1.second)
            {
                cout << it2 << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n, m, u, v;
    Graph *g = new Graph;
    cout << "Enter No. of Nodes: ";
    cin >> n;
    cout << "Enter No. of Edges: ";
    cin >> m;
    cout << "Enter Edges: \n";
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        g->insertEdge(u, v, true);
    }
    g->printAdjacenyList();
    cout << endl;
    return 0;
}

/*
5
6
1 2
2 3
3 4
4 5
5 1
2 4
*/