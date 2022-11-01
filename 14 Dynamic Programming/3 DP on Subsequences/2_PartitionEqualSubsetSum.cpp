#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool memoisation(int idx, int target, vector<int> &nums, vector<vector<int>> &dp)
    {
        if(idx < 0)   
            return false;
        if(nums[idx] == target)
            return true;
        if(dp[idx][target] != -1)
            return dp[idx][target];
        
        bool nottake = memoisation(idx-1, target, nums, dp);
        bool take  = false;
        if(nums[idx] < target)
            take = memoisation(idx-1, target - nums[idx], nums, dp);
        
        dp[idx][target] = take || nottake;
        return dp[idx][target];
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0, target;
        for(int i = 0; i<n; i++)
        {
            sum += nums[i];
        }
        if(sum % 2 != 0)
            return false;
        target = sum / 2;
        vector<vector<int>> dp(n, vector<int> (target+1, -1));
        return memoisation(n-1, target, nums, dp);
    }
};