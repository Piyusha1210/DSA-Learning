#include <bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, set<int>> adj;
    unordered_map<int, bool> visited, dfsVisited;

public:
    void insertEdge(int u, int v)
    {
        adj[u].insert(v);
        // adj[v].insert(u);
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

    bool isCyclicDFS(int root)
    {
        if (visited[root])
        {
            if (dfsVisited[root])
                return true;
            else
                return false;
        }
        visited[root] = true;
        dfsVisited[root] = true;
        for (auto it : adj[root])
        {
            if (isCyclicDFS(it))
                return true;
        }
        dfsVisited[root] = false;
        return false;
    }

    void detectCycle()
    {
        bool ans;
        for (auto it : adj)
        {
            if (!visited[it.first])
            {
                ans = isCyclicDFS(it.first);
            }
        }
        if (ans)
            cout << "Cycle Detected" << endl;
        else
            cout << "No Cycle Detected" << endl;

        return;
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
        g->insertEdge(u, v);
    }
    g->printAdjacenyList();
    cout << endl;

    g->detectCycle();
    return 0;
}

/*
5
5
1 2
2 3
3 4
4 5
2 4
5 1
*/