#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/maximum-sum-circular-subarray/description/
class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // Kadan's Algo
        int currMaxSum = 0, currMinSum = 0, minSum = INT_MAX, maxSum = INT_MIN, totalSum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            currMaxSum += nums[i];
            currMinSum += nums[i];
            totalSum += nums[i];
            
            maxSum = max(maxSum, currMaxSum);
            minSum = min(minSum, currMinSum);

            if(currMaxSum < 0)
                currMaxSum = 0;
            if(currMinSum > 0)
                currMinSum = 0;

        }
        return maxSum > 0 ? max(maxSum, totalSum - minSum): maxSum;
    }
};