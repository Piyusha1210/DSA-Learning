#include <bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1

class Solution
{
public:
    void dfs(int root, vector<pair<int, int>> adj[], vector<bool> &visited, stack<int> &st)
    {
        if (visited[root])
            return;

        visited[root] = true;
        for (auto it : adj[root])
        {
            dfs(it.first, adj, visited, st);
        }
        st.push(root);
        return;
    }

    vector<int> shortestPath(int N, int M, vector<vector<int>> &edges)
    {
        vector<pair<int, int>> adj[N];
        for (int i = 0; i < M; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
        }

        // Valid only for Directed Acyclic Graph DAG.
        // First Find Topological Sort for Graph
        stack<int> st;
        vector<bool> visited(N, false);
        for (int i = 0; i < N; i++)
        {
            dfs(i, adj, visited, st);
        }

        vector<int> dis(N, INT_MAX);
        dis[0] = 0; // Dist of SOurce is Zero.

        // Now take out one by one top of stack(topological order)
        // check routes from it to edges have less distance
        // If distance of node is INT_MAX then set it to -1 as given in que

        while (!st.empty())
        {
            int t = st.top();
            st.pop();
            if (dis[t] == INT_MAX)
            {
                dis[t] = -1;
                continue;
            }
            for (auto it : adj[t])
            {
                if (dis[it.first] > dis[t] + it.second)
                {
                    dis[it.first] = dis[t] + it.second;
                }
            }
        }
        return dis;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends