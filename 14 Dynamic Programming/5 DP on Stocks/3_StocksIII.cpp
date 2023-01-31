#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/
class Solution {
public:
    int memoisation(int idx, int buy, int trans, vector<int>& prices, vector<vector<vector<int>>> &dp)
    {
        if(idx == prices.size())
            return 0;

        if(trans == 0)
            return 0;
            
        if(dp[idx][buy][trans] != -1)
            return dp[idx][buy][trans];
        
        int profit = 0;
        if(buy)
        {
            // if buy == 1 then only
            int buyIt = -prices[idx] + memoisation(idx+1, 0, trans, prices, dp);
            int notBuyIt = memoisation(idx+1, 1, trans, prices, dp);
            profit = max(buyIt, notBuyIt);
        }
        else
        {
            // if buy == 0 then only
            int sellIt = prices[idx] + memoisation(idx+1, 1, trans-1, prices, dp);
            int notSellIt = memoisation(idx+1, 0, trans, prices, dp);
            profit = max(sellIt, notSellIt);
        }
        dp[idx][buy][trans] = profit;
        return dp[idx][buy][trans];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        return memoisation(0, 1, 2, prices, dp);
    }
};