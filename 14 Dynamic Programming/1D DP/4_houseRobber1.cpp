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
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return memoisation(n-1, nums, dp);
    }
};