#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/is-graph-bipartite/submissions/1321931496/

class Solution {
public:
    bool bfs(int root, vector<bool> &visited, vector<int> &color, vector<vector<int>> &graph)
    {
        queue<int> qu;
        qu.push(root);
        while(!qu.empty())
        {
            int t = qu.front();
            int c = color[t];
            qu.pop();
            for(auto it: graph[t])
            {
                if(visited[it])
                {
                    if(color[it] == c)
                        return true;
                }
                else
                {
                    qu.push(it);
                    visited[it] = true;
                    color[it] = (c+1) % 2;
                }
            }
        }
        return false;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        vector<bool> visited(n, false);

        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                if(bfs(i, visited, color, graph))
                    return false;
            }
        }
        return true;
    }
};