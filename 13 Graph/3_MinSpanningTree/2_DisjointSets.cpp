//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class DisjointSet
{
    vector<int> rank, size, parent;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findPar(int node)
    {
        if (node == parent[node])
            return node;

        return parent[node] = findPar(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findPar(u); // Ultimate Parent u
        int ulp_v = findPar(v); // Ultimate Parent v

        if (ulp_u == ulp_v)
            return;

        else if (rank[ulp_u] >= rank[ulp_v])
        {
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = ulp_u;
        }
        else
        {
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = ulp_v;
        }
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findPar(u); // Ultimate Parent u
        int ulp_v = findPar(v); // Ultimate Parent v

        if (ulp_u == ulp_v)
            return;

        if (rank[ulp_u] < rank[ulp_v])
            parent[ulp_u] = ulp_v;

        else if (rank[ulp_u] > rank[ulp_v])
            parent[ulp_v] = ulp_u;

        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

int main()
{
    DisjointSet ds(7);
    /*
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    if (ds.findPar(3) == ds.findPar(7))
        cout << "Same Parrent - " << ds.findPar(3) << endl;
    else
        cout << "Not Same\n";

    ds.unionByRank(3, 7);
    if (ds.findPar(3) == ds.findPar(7))
        cout << "Same Parrent - " << ds.findPar(3) << endl;
    else
        cout << "Not Same\n";
    */

    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    if (ds.findPar(3) == ds.findPar(7))
        cout << "Same Parrent - " << ds.findPar(3) << endl;
    else
        cout << "Not Same\n";

    ds.unionBySize(3, 7);
    if (ds.findPar(3) == ds.findPar(7))
        cout << "Same Parrent - " << ds.findPar(3) << endl;
    else
        cout << "Not Same\n";

    return 0;
}

// } Driver Code Ends