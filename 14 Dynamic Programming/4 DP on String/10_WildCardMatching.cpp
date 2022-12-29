#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int memoisation(int i, int j, string &s, string &p, vector<vector<int>> &dp)
    {
        if(i < 0 && j < 0)
            return 1;
        if(i < 0)
        {
            if(p[j] == '*')
                return memoisation(i, j-1, s, p, dp);
            return 0;
        }
        if(j < 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(s[i] == p[j] || p[j] == '?')
        {
            dp[i][j] = memoisation(i-1, j-1, s, p, dp);
            return dp[i][j];
        }
        if(p[j] == '*')
        {
            int idx = i;
            while(idx >= -1)
            {
                // cout<<"work " << idx << " " << j-1<<endl;
                if(memoisation(idx, j-1, s, p, dp))
                {
                    dp[i][j] = 1;
                    return dp[i][j];
                }
                idx--;
            }
            dp[i][j] = 0;
            return dp[i][j];
        }     
        dp[i][j] = 0;
        return dp[i][j];
    }

    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return memoisation(n-1, m-1, s, p, dp);
    }
};
