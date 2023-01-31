#include<bits/stdc++.h>
using namespace std;

// https : // leetcode.com/problems/best-team-with-no-conflicts/description/
class Solution
{
public:
    int memoisation(int idx, int prev, vector<pair<int, int>> &vp, vector<vector<int>> &dp)
    {
        if (idx == vp.size())
            return 0;

        if (dp[idx][prev + 1] != -1)
            return dp[idx][prev + 1];

        int nottake = memoisation(idx + 1, prev, vp, dp);
        int take = 0;
        if (prev == -1 || vp[idx].second >= vp[prev].second)
        {
            take = memoisation(idx + 1, idx, vp, dp) + vp[idx].second;
        }
        dp[idx][prev + 1] = max(take, nottake);
        return dp[idx][prev + 1];
    }

    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        int n = ages.size();
        vector<pair<int, int>> vp;
        for (int i = 0; i < n; i++)
        {
            vp.push_back({ages[i], scores[i]});
        }
        sort(vp.begin(), vp.end());
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return memoisation(0, -1, vp, dp);
    }
};