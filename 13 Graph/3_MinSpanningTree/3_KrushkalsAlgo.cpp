//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class disJointSet
{
    vector<int> parent;
    vector<int> size;

public:
    disJointSet(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findParent(int node)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }

    void joinBySize(int u, int v)
    {
        int upu = findParent(u);
        int upv = findParent(v);
        if (upu == upv)
            return;
        if (size[upu] >= size[upv])
        {
            size[upu] += size[upv];
            parent[upv] = upu;
        }
        else
        {
            size[upv] += size[upu];
            parent[upu] = upv;
        }
        return;
    }
};

class Solution
{
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        /* First sort all the edges according to their weight by which be can traverse them by their weight */
        vector<vector<int>> edges;
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int neig = it[0];
                int wt = it[1];
                edges.push_back({wt, i, neig});
            }
        }
        sort(edges.begin(), edges.end()); // M log M

        int sum = 0;
        disJointSet ds(edges.size());
        // M * 4 * alpha

        /* Now We have to create a disJoint Data structure with the help of that we can find out if the edges nodes are already connected by some other path or not

        if connected then their ultimate parrent must be same and in that sace no need to add that  edge in Minimum Spanning Tree MST

        If not common parent then they two are from two diff disjoint sets then add the edge and combine sets
        */

        for (int i = 0; i < edges.size(); i++)
        {
            int w = edges[i][0], u = edges[i][1], v = edges[i][2];
            int pu = ds.findParent(u);
            int pv = ds.findParent(v);
            if (pu != pv)
            {
                sum += w;
                ds.joinBySize(pu, pv);
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