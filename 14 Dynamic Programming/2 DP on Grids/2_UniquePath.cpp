#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int memoisation(int row, int col, vector<vector<int>> &dp)
    {        
        if (row == 0 || col == 0)
        {
            return 1;
        }
        
        if(dp[row][col] != -1)
            return dp[row][col];
        
        dp[row][col] = memoisation(row-1, col, dp) + memoisation(row, col-1, dp);
        return dp[row][col];
    }
    
    int tabulation(int row, int col)
    {
        vector<int> temp(col, 1);
        vector<int> ans = temp;
        for(int i = 1; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(j == 0)
                    ans[j] = 1;
                else
                    ans[j] = temp[j] + ans[j-1];
            }
            temp = ans;
        }
        return ans[col-1];
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        // return memoisation(m-1, n-1, dp);
        return tabulation(m, n);
    }
};