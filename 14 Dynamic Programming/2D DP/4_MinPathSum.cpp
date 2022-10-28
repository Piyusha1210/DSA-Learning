#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int memoisation(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        if(row == 0 && col == 0)
            return grid[0][0];
        
        if(dp[row][col] != -1)
            return dp[row][col];
        
        if(row == 0)
        {   
            dp[row][col] = memoisation(row, col-1, grid, dp) + grid[row][col];
            return dp[row][col];
        }
        if(col == 0)
        {   
            dp[row][col] = memoisation(row-1, col, grid, dp) + grid[row][col];
            return dp[row][col];
        }
        dp[row][col] = min(memoisation(row-1, col, grid, dp), memoisation(row, col-1, grid, dp)) + grid[row][col];
        return dp[row][col];
    }
    
    int tabulation(int m, int n, vector<vector<int>>& grid)
    {
        int dp[m][n];
        dp[0][0] = grid[0][0];
        for(int i = 1; i < max(m, n); i++)
        {
            if(i < m)
                dp[i][0] = dp[i-1][0] + grid[i][0];
            if(i < n)
                dp[0][i] = dp[0][i-1] + grid[0][i];
        }

        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return memoisation(n-1, m-1, grid, dp);
        return tabulation(n, m, grid);
    }
};