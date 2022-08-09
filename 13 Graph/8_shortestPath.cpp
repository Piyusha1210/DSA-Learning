#include <bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, set<int>> adj;
    unordered_map<int, int> parent;
    unordered_map<int, bool> visited;

public:
    void insertEdge(int u, int v)
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

    void shortestPath()
    {
        int s, t;
        cout << "Enter starting & Ending Vertices\n";
        cin >> s >> t;
        queue<int> q;
        q.push(s);
        visited[s] = true;
        parent[s] = -1;

        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            for (auto it : adj[front])
            {
                if (visited[it] == false)
                {
                    q.push(it);
                    visited[it] = true;
                    parent[it] = front;
                }
            }
        }
        vector<int> ans;
        int current = t;
        ans.push_back(current);
        while (current != s)
        {
            current = parent[current];
            ans.push_back(current);
        }
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << "-> ";
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
        g->insertEdge(u, v);
    }
    g->printAdjacenyList();
    cout << endl;

    g->shortestPath();
    return 0;
}

/*
8
9
1 2
1 3
1 4
2 5
4 6
6 7
5 8
3 8
7 8
*/