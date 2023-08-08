#include <bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, set<int>> adj;
    unordered_map<int, bool> dfsVisited;
    vector<int> dfsList;

public:
    void insertEdge(int u, int v, bool direction)
    {
        // direction->0 Directed
        // direction->1 UnDirected
        adj[u].insert(v);
        if (direction == 1)
            adj[v].insert(u);
        return;
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

    void dfs(int root)
    {
        stack<int> s;
        s.push(root);
        dfsVisited[root] = true;
        while (!s.empty())
        {
            int top = s.top();
            s.pop();
            dfsList.push_back(top);
            for (auto it : adj[top])
            {
                if (!dfsVisited[it])
                {
                    s.push(it);
                    dfsVisited[it] = true;
                }
            }
        }
        return;
    }
    void dfsRecursion(int root)
    {
        if (dfsVisited[root])
            return;
        dfsList.push_back(root);
        dfsVisited[root] = true;
        for (auto it : adj[root])
        {
            dfsRecursion(it);
        }
        return;
    }

    void dfsTraversal()
    {
        cout << "DFS Traversal:\n";
        for (auto it : adj)
        {
            if (!dfsVisited[it.first])
                dfsRecursion(it.first);
        }
        for (int i = 0; i < dfsList.size(); i++)
        {
            cout << dfsList[i] << "->";
        }
        cout << endl;
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

    g->dfsTraversal();
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