#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<int> dp(n+1);
        int ans = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = i-1; j >= 0; j--)
            {
                if(j == 0 || a[i-1] > a[j-1])
                {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};