#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// https://leetcode.com/contest/biweekly-contest-101/problems/shortest-cycle-in-a-graph/
class Solution
{
public:
    int findShortestCycle(int n, vector<vector<int>> &edges)
    {
        vector<int> mp[n];
        for (int i = 0; i < edges.size(); i++)
        {
            mp[edges[i][0]].push_back(edges[i][1]);
            mp[edges[i][1]].push_back(edges[i][0]);
        }

        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            vector<int> dist(n, INT_MAX);
            vector<int> par(n, -1);
            dist[i] = 0;

            queue<int> q;
            q.push(i);

            while (!q.empty())
            {
                int x = q.front();
                q.pop();
                for (int child : mp[x])
                {
                    if (dist[child] == INT_MAX)
                    {
                        dist[child] = 1 + dist[x];
                        par[child] = x;
                        q.push(child);
                    }
                    else if (par[x] != child and par[child] != x)
                    {
                        ans = min(ans, dist[x] + dist[child] + 1);
                    }
                }
            }
        }
        if (ans == INT_MAX)
            return -1;
        else
            return ans;
    }
};