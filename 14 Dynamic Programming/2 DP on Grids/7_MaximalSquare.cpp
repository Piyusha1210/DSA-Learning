#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/maximal-square/?envType=study-plan&id=dynamic-programming-i

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(matrix[i-1][j-1] == '0')
                {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
                ans = max(ans, dp[i][j]);
            }
        }
        return ans*ans;
    }
};