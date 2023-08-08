//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   S: source vertex to start traversing graph with
     *   V: number of vertices
     */

    vector<int> bellman_ford(int V, vector<vector<int>> &edges, int S)
    {
        vector<int> dis(V, 1e8);
        dis[S] = 0;

        /*
            Bellman Ford is valid for only Directed Graph, If Graph is not directed then make it first directed by adding parallel edges in opp dir.

            Their shouldn't be any negative edge cycle - Cycle in which their is a neagtive edge.
            If neagtive edge then it will neven end.

            In Bellman-Ford Algo we iterte for n-1 times for every edge by iterating for n-1 times we are supposed to cover every vertex.
        */

        for (int i = 0; i < V - 1; i++)
        {
            for (auto it : edges)
            {
                int u = it[0];
                int v = it[1];
                int w = it[2];
                if (dis[u] + w < dis[v])
                    dis[v] = dis[u] + w;
            }
        }

        // If therir is still any change in distance vector possible that means their is a negative edge cycle, which will never end;

        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if (dis[u] + w < dis[v])
                return {-1};
        }

        // T.C. -> V*E
        // S.C -> V
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
        int N, m;
        cin >> N >> m;
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

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res)
        {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends