#include<bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int>& nums, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
    }
    int k = sum / 2;
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    dp[0][nums[0]] = true;
    for (int idx = 1; idx < n; idx++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool nottake = dp[idx - 1][target];
            bool take = false;
            if (nums[idx] <= target)
                take = dp[idx - 1][target - nums[idx]];
            dp[idx][target] = take || nottake;
        }
    }
    int t = k;
    while (dp[n - 1][t] != true && t>0)
    {
        t--;
    }
    return sum - (2 * t);
}
