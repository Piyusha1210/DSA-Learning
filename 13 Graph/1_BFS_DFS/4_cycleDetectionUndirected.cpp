#include <bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, set<int>> adj;
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

public:
    void insertEdge(int u, int v, bool direction)
    {
        adj[u].insert(v);
        adj[v].insert(u);
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

    bool isCyclicBFS(int root)
    {
        queue<int> q;
        q.push(root);
        visited[root] = true;
        parent[root] = -1;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            for (auto it : adj[front])
            {
                if (!visited[it])
                {
                    q.push(it);
                    visited[it] = true;
                    parent[it] = front;
                }
                else
                {
                    if (parent[front] == it)
                        continue;
                    else
                        return true;
                }
            }
        }
        return false;
    }

    bool isCyclicDFS(int root, int p)
    {
        if (visited[root])
        {
            if (parent[p] == root)
                return false;
            else
                return true;
        }
        parent[root] = p;
        visited[root] = true;
        for (auto it : adj[root])
        {
            if (isCyclicDFS(it, root))
                return true;
        }
        return false;
    }

    void detectCycle()
    {
        bool ans;
        for (auto it : adj)
        {
            if (!visited[it.first])
            {
                // ans = isCyclicBFS(it.first);
                ans = isCyclicDFS(it.first, -1);
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
        g->insertEdge(u, v, true);
    }
    g->printAdjacenyList();
    cout << endl;

    g->detectCycle();
    return 0;
}

/*
5
4
1 2
2 3
3 4
4 5
5 1
2 4
*/