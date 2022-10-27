#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int memoisation(int idx, vector<int> nums, vector<int> &dp)
    {
        if(idx < 0)    
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        int pick = memoisation(idx-2, nums, dp) + nums[idx];
        int notpick = memoisation(idx-1, nums, dp);
        dp[idx] = max(pick, notpick);
        return dp[idx];
    }
    
    int tabulation(int idx, vector<int> nums, vector<int> &dp)
    {
        dp[0] = nums[0];
        if(idx >= 1)
            dp[1] = max(dp[0], nums[1]);
        for(int i = 2; i <= idx; i++)
        {
            int pick = nums[i] + dp[i-2];
            int notpick = dp[i-1];
            dp[i] = max(pick, notpick);
        }
        return dp[idx];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)
            return nums[0];
        
        // Both First & Last House can't be looted together as Cycle present
        // so we took only one of them at a time.

        vector<int> dp1(n, -1);
        int a = memoisation(n-2, nums, dp1);
        int a = tabulation(n-2, nums, dp1);
        nums.erase(nums.begin());
        vector<int> dp2(n, -1);
        int b = memoisation(n-2, nums, dp2);
        int b = tabulation(n-2, nums, dp2);
        // cout<<a<<" "<<b;
        return max(a, b);
    }
};