#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int memoisation(int i, int j, string &s, string &t, vector<vector<int>> &dp)
    {
        if(i < 0 || j < 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(s[i] == t[j])
        {
            dp[i][j] = 1 + memoisation(i-1, j-1, s, t, dp);
            return dp[i][j];
        }
        int v1 = memoisation(i-1, j, s, t, dp);
        int v2 = memoisation(i, j-1, s, t, dp);
        dp[i][j] = max(v1, v2);
        return dp[i][j];
    }

    int minInsertions(string s) {
        string r = s;
        reverse(r.begin(), r.end());
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int longestPallindromicSubsequence = memoisation(n-1, n-1, s, r, dp);
        return n - longestPallindromicSubsequence;
    }
};