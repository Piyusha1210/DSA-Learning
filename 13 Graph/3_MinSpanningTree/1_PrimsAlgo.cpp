//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int sum = 0;
        vector<bool> visited(V, false);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0});
        /*
        Make a pq in which we will store {weight, node} & create a visited array
        In this pq we will pop out edge with min edge weight &
        push all the other edges to that node to those nodes that are unvisited
        */

        while (!pq.empty())
        {
            vector<int> v = pq.top();
            pq.pop();
            int w = v[0], node = v[1];

            if (visited[node])
                continue;
            visited[node] = true;
            sum += w;
            for (auto it : adj[node])
            {
                if (visited[it[0]] == false)
                    pq.push({it[1], it[0]});
            }
        }
        return sum;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends