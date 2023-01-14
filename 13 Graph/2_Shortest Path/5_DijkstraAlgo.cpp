//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // We have created a pq in which we push pair of distance and node in that we will get the node with mini distance at top of pq;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dis(V, INT_MAX);
        dis[S] = 0;
        pq.push({0, S});
        while (!pq.empty())
        {
            pair<int, int> temp = pq.top();
            pq.pop();
            int d = temp.first;
            int node = temp.second;
            for (auto it : adj[node])
            {
                if (dis[it[0]] > d + it[1])
                {
                    dis[it[0]] = d + it[1];
                    pq.push({dis[it[0]], it[0]});
                }
            }
        }
        return dis;
        // Dijkstra Algo doesn't work for edges with negative weight, If their is neg weight then their will be an infinite loop.

        // If we take queue here instead of pq then we will unnecessarily accessing first the longer paths else if we use pq then firts we will access shorter paths.
    }
};

//{ Driver Code Starts.

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
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends