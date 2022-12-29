#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int recursion(int i, int j, string &s, string &t, vector<vector<int>> &dp1, vector<vector<int>> &dp2)
    {
        if(i == 0 || j == 0)
            return 1;
        
        if(dp2[i][j] != -1) 
            return dp2[i][j];

        int ans = 0;
        if(s[i-1] == t[j-1])
            ans += recursion(i-1, j-1, s, t, dp1, dp2);
            
        if(dp1[i-1][j] == dp1[i][j])
            ans += recursion(i-1, j, s, t, dp1, dp2);
        
        if(dp1[i][j-1] == dp1[i][j])
            ans += recursion(i, j-1, s, t, dp1, dp2);
        
        dp2[i][j] = ans;
        return ans;
    }

    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size(), ans = 0;
        vector<vector<int>> dp1(n+1, vector<int>(m+1, 0));
        vector<vector<int>> dp2(n+1, vector<int>(m+1, -1));

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(s[i-1] == t[j-1])
                    dp1[i][j] = dp1[i-1][j-1] + 1;

                else if(dp1[i-1][j] > dp1[i][j-1])
                    dp1[i][j] = dp1[i-1][j];

                else
                    dp1[i][j] = dp1[i][j-1];
            }
        }
        if(dp1[n][m] != m)
            return 0;
        
        ans = recursion(n, m, s, t, dp1, dp2);
        return ans;
    }
};