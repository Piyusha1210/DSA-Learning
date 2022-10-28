#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int memoisation(int row, int col, vector<vector<int>>& triangle, vector<vector<int>>& dp)
    {
        if(row == triangle.size() - 1)
            return triangle[row][col];
        
        if(dp[row][col] != -1)
            return dp[row][col];
        
        dp[row][col] = min(memoisation(row+1, col, triangle, dp), memoisation(row+1, col+1, triangle, dp)) + triangle[row][col];
        return dp[row][col];
    }
    
    int tabulation(int n, vector<vector<int>>& triangle)
    {
        int dp[n][n];
        dp[0][0] = triangle[0][0];
        for(int i = 1; i < n ; i++)
        {
            for(int j = 0; j <= i; j++)
            {
                if(j == 0)
                    dp[i][j] = dp[i-1][j];
                else if(j == i)
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]);
                dp[i][j] += triangle[i][j];
            }
        }
        int ans = INT_MAX;
        for(int j = 0; j<n; j++)
        {
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }
    // Variable Destination - No fixed ending Point so we will start from top here
    
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return memoisation(0, 0, triangle, dp);
        // return tabulation(n, triangle);
    }
};