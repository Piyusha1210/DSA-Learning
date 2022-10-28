#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int  memoisation(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp)
    {
        if(col == -1 || col == matrix.size())
            return INT_MAX;
        
        if(row == 0)
            return matrix[row][col];
        
        if(dp[row][col] != -1)
            return dp[row][col];
        
        dp[row][col] = matrix[row][col];
        
        int left = memoisation(row-1, col-1, matrix, dp);
        int up = memoisation(row-1, col, matrix, dp);
        int right = memoisation(row-1, col+1, matrix, dp);
        
        dp[row][col] += min(left, min(up, right));
        
        return dp[row][col];
    }
    
    int tabulation(int n, vector<vector<int>>& matrix) 
    {
        int dp[n][n];        
        for(int i = 0; i < n; i++)
        {
                dp[0][i] = matrix[0][i];
        }
        for(int i = 1; i < n ; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(j == 0)
                {
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j+1]);                   
                }
                else if(j == n-1)
                {
                    dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]);                   
                }
                else
                {
                    dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i-1][j+1]));                 }
                dp[i][j] += matrix[i][j];
            }
        }
        int ans = INT_MAX;
        for(int j = 0; j<n; j++)
        {
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>> dp(n, vector<int> (n, -1));
        for(int j = 0; j<n; j++)
        {
            ans = min(ans, memoisation(n-1, j, matrix, dp));
        }
        return ans;
        return tabulation(n, matrix);
    }
};