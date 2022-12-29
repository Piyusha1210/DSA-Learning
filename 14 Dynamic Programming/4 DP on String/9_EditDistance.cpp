#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int memoisation(int i, int j, string &word1, string &word2, vector<vector<int>> &dp)
    {
        if(i < 0)
            return j+1;
        if(j < 0)
            return i+1;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        if(word1[i] == word2[j])
        {
            dp[i][j] = memoisation(i-1, j-1, word1, word2, dp);
            return dp[i][j];
        }

        int inser = 1 + memoisation(i, j-1, word1, word2, dp);
        int delet = 1 + memoisation(i-1, j, word1, word2, dp);
        int replac = 1 + memoisation(i-1, j-1, word1, word2, dp);
        
        dp[i][j] = min(replac,  min(inser, delet));
        return dp[i][j];
    }

    int tabulation(string &word1, string &word2)
    {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i = 0; i <= n; i++)
            dp[i][0] = i;
        for(int j = 0; j <= m; j++)
            dp[0][j] = j;

        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(word1[i-1] == word2[j-1])
                {
                    dp[i][j] = dp[i-1][j-1];
                    continue;
                }
                int inser = 1 + dp[i][j-1];
                int delet = 1 + memoisation(i-1, j, word1, word2, dp);
                int replac = 1 + memoisation(i-1, j-1, word1, word2, dp);
                
                dp[i][j] = min(replac,  min(inser, delet));        
            }
        }
        return dp[n][m];
    }

    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return memoisation(n-1, m-1, word1, word2, dp);
        return tabulation(word1, word2);
    }
};