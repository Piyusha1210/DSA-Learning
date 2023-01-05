#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int memoisation(int idx, int prev, vector<int> &nums, vector<vector<int>> &dp)
    {
        if(idx == nums.size()+1)
            return 0;
        
        if(dp[idx][prev] != -1)
            return dp[idx][prev];
            
        int nottake = memoisation(idx+1, prev, nums, dp);
        int take = 0;
        if(prev == 0 || nums[idx-1] > nums[prev-1])
            take = 1 + memoisation(idx+1, idx, nums, dp);
        
        dp[idx][prev] = max(take, nottake);
        return dp[idx][prev];        
    }

    int tabulation(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n+1);
        for(int i = 1; i <= n; i++)
        {
            for(int j = i-1; j >= 0; j--)
            {
                if(j == 0 || nums[i-1] > nums[j-1])
                {
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        return dp[n];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return memoisation(1, 0, nums, dp);
        // return tabulation(nums);
    }
};