#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/accounts-merge/description/
class disJointSet{
public:
    vector<int>parent;
    vector<int>size;
    disJointSet(int n)
    {
        parent.resize(n,-1);
        size.resize(n, 1);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }
    int findParent(int n)
    {
        if(parent[n] == n)
            return n;
        return parent[n] = findParent(parent[n]);
    }
    void joinBySize(int u, int v)
    {
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(size[ulp_u] >= size[ulp_v])
            parent[ulp_v] = ulp_u;
        else
            parent[ulp_u] = ulp_v;
        return;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        disJointSet ds(n);
        unordered_map<string, int> mapMail;
        for(int i = 0; i < n; i++)
        {
            for(int j = 1; j < accounts[i].size(); j++)
            {
                string mail = accounts[i][j];
                if(mapMail.find(mail) == mapMail.end())
                    mapMail[mail] = i;
                else
                    ds.joinBySize(i, mapMail[mail]);
            }
        }

        vector<vector<string>> ans(n);
        for(int i = 0; i < n; i++)
            ans[i].push_back(accounts[i][0]);

        for(auto it: mapMail)
        {
            string mail = it.first;
            int node = ds.findParent(it.second);
            ans[node].push_back(mail);
        }
        for(int i = 0; i < ans.size(); i++)
        {
            if(ans[i].size() == 1)
            {
                ans.erase(ans.begin()+i);
                i--;
                continue;
            }
            sort(ans[i].begin()+1, ans[i].end());
        }
        return ans;
    }
};