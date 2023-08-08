#include <bits/stdc++.h>
using namespace std;

class Graph
{
    map<int, set<pair<int, int>>> adj;
    unordered_map<int, int> parent;
    unordered_map<int, bool> visited;

public:
    void insertEdge(int u, int v, int w)
    {
        adj[u].insert({v, w});
    }
    void printAdjacenyList()
    {
        for (auto it1 : adj)
        {
            cout << it1.first << " -> ";
            for (auto it2 : it1.second)
            {
                cout << "[" << it2.first << " " << it2.second << "] ";
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
                if (visited[it.first] == false)
                {
                    q.push(it.first);
                    visited[it.first] = true;
                    parent[it.first] = front;
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
    int n, m, u, v, w;
    Graph *g = new Graph;
    cout << "Enter No. of Nodes: ";
    cin >> n;
    cout << "Enter No. of Edges: ";
    cin >> m;
    cout << "Enter Edges: \n";
    // Directed Acyclic Graph
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        g->insertEdge(u, v, w);
    }
    g->printAdjacenyList();
    cout << endl;

    g->shortestPath();
    return 0;
}

/*
6
9
1 2 2
1 3 6
6 1 5
6 2 3
3 4 -1
2 3 7
2 4 4
2 5 2
4 5 -2
*/