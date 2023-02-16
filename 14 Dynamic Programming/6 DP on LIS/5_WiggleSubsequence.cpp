#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/wiggle-subsequence/description/?envType=study-plan&id=dynamic-programming-i

class Solution {
public:
    int memoisation(int idx, int prev, int sign, vector<int> &nums, vector<vector<vector<int>>> &dp)
    {
        if(idx == nums.size()+1)
            return 0;
        
        if(dp[idx][prev][sign] != -1)
            return dp[idx][prev][sign];

        int nottake = memoisation(idx+1, prev, sign, nums, dp);
        int take = 0;
        if(sign == 0)
        {
            if(prev == 0 || nums[idx-1] > nums[prev-1])
                take = memoisation(idx+1, idx, 1, nums, dp) + 1;
        }
        else
        {
            if(prev == 0 || nums[idx-1] < nums[prev-1])
                take = memoisation(idx+1, idx, 0, nums, dp) + 1;
        }

        dp[idx][prev][sign] = max(take, nottake);
        return dp[idx][prev][sign];
    }

    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(2, -1)));
        return max(memoisation(1, 0, 0, nums, dp), memoisation(1, 0, 1, nums, dp));
    }
};