#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    map<int, set<int>> adj;
    unordered_map<int, bool> visited, dfsVisited;
    stack<int> st;
    vector<int> topologicalSort;

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
        st.push(root);
        dfsVisited[root] = false;
        return false;
    }

    bool detectCycle()
    {
        bool ans;
        for (auto it : adj)
        {
            if (!visited[it.first])
            {
                // ans = isCyclicBFS(it.first);
                ans = isCyclicDFS(it.first);
            }
        }
        if (ans)
            cout << "Cycle Detected" << endl;
        else
        {
            // cout << "No Cycle Detected" << endl;
            while (!st.empty())
            {
                topologicalSort.push_back(st.top());
                st.pop();
            }
        }
        return ans;
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

    // for DAG -> Directed Acyclic Graph Only
    // for cycle issue 1->2; 2->3; 3->1;

    if (!g->detectCycle())
    {
        for (int i = 0; i < g->topologicalSort.size(); i++)
        {
            cout << g->topologicalSort[i] << " ";
        }
    }
    return 0;
}

/*
Test Case - 1
5
5
1 2
2 3
3 4
4 5
2 4
5 1

Test Case - 2
4
4
0 1
1 2
0 3
3 2
*/
