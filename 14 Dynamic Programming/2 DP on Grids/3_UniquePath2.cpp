#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int memoisation(int row, int col, vector<vector<int>>& obstacleGrid, vector<vector<int>> &dp)
    {
        if (row < 0 || col < 0)
            return 0;
        if(obstacleGrid[row][col] == 1)
            return 0;
        if(row == 0 && col == 0)
            return 1;
        
        if(dp[row][col] != -1)
            return dp[row][col];
        
        dp[row][col] = memoisation(row-1, col, obstacleGrid, dp) + memoisation(row, col-1, obstacleGrid, dp);
        return dp[row][col];
    }
    
    int tabulation(int row, int col, vector<vector<int>>& obstacleGrid)
    {
        vector<int> temp(col);
        if(obstacleGrid[0][0] == 1)
            temp[0] = 0;
        else
            temp[0] = 1;
        for(int i = 1; i<col; i++)
        {
            if(obstacleGrid[0][i] == 1)
                temp[i] = 0;
            else
                temp[i] = temp[i-1];
        }
        vector<int> ans = temp;
        for(int i = 1; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(obstacleGrid[i][j] == 1)
                    ans[j] = 0;
                
                else if(j == 0)
                    ans[j] = temp[j];
                else
                    ans[j] = temp[j] + ans[j-1];
            }
            temp = ans;
        }
        return ans[col-1];
    }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m =  obstacleGrid[0].size();
        
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return memoisation(n-1, m-1, obstacleGrid,dp);
        
        return tabulation(n, m, obstacleGrid);
    }
};