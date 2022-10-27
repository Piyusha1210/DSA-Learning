#include <bits/stdc++.h>
using namespace std;
int memo(int n, vector<int> heights, vector<int> &dp)
{
    if(dp[n] != -1)
        return dp[n];
    
    int oneStep = memo(n-1, heights, dp) + abs(heights[n] - heights[n-1]);
    int twoStep = memo(n-2, heights, dp) + abs(heights[n] - heights[n-2]);
    dp[n] = min(oneStep, twoStep);
    return dp[n];
}
int tabulation(int n, vector<int> heights)
{
    int a = 0;
    int b = abs(heights[1] - heights[0]);
    for(int i = 2; i <= n; i++)
    {
        int c = min(a+abs(heights[i] - heights[i-2]), b+abs(heights[i] - heights[i-1]));
        a = b;
        b = c;
    }
    return b;
}
int frogJump(int n, vector<int> &heights)
{
    if(n == 1)
        return 0;
    vector<int> dp(n, -1);
    dp[0] = 0;
    dp[1] = abs(heights[1] - heights[0]);
//     return memo(n-1, heights, dp);
    return tabulation(n-1, heights);
}