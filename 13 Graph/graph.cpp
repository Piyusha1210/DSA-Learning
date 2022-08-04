#include <bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, set<int>> adj;
    unordered_map<int, bool> bfsVisited, dfsVisited;
    vector<int> bfsList;
    vector<int> dfsList;

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

    void bfs(int root)
    {
        queue<int> q;
        q.push(root);
        bfsVisited[root] = true;
        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            bfsList.push_back(front);
            for (auto it : adj[front])
            {
                if (!bfsVisited[it])
                {
                    q.push(it);
                    bfsVisited[it] = true;
                }
            }
        }
        return;
    }
    void bfsTraversal()
    {
        for (auto it : adj)
        {
            if (!bfsVisited[it.first])
                bfs(it.first);
            // cout << "work\n";
        }
        cout<<"BFS Traversal:\n";
        for (int i = 0; i < bfsList.size(); i++)
        {
            cout << bfsList[i] << "->";
        }
        cout<<endl;
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
    void dfsTraversal()
    {
        for (auto it : adj)
        {
            if (!dfsVisited[it.first])
                dfs(it.first);
        }
        cout<<"DFS Traversal:\n";
        for (int i = 0; i < dfsList.size(); i++)
        {
            cout << dfsList[i] << "->";
        }
        cout<<endl;
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
    cout<<endl;

    // For BFS Traversal
    g->bfsTraversal();
    g->dfsTraversal();
    cout<<"work";
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