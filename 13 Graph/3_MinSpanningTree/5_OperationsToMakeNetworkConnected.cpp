#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/

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

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int ans = 0, m = connections.size();
        if(m < n-1)
            return -1;
        disJointSet ds(n);

        for(int i = 0; i < m; i++)
        {
            int u = connections[i][0], v = connections[i][1];
            int pu = ds.findParent(u);
            int pv = ds.findParent(v);
            if (pu != pv)
            {
                ds.joinBySize(pu, pv);
            }
        }

        for(int u = 0; u < n; u++)
        {
            if (u == ds.findParent(u))
                ans++;                
        }
        return ans-1;
    }
};