#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1), hash(n, -1), ans;
        sort(nums.begin(), nums.end());
        int maxi = 0, maxidx = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j <= i-1; j++)
            {
                if(nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
            if(dp[i] > maxi)
            {
                maxi = dp[i];
                maxidx = i;
            }
        }
        while(maxidx > -1)
        {
            ans.push_back(nums[maxidx]);
            maxidx = hash[maxidx];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};