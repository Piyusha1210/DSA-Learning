#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

class Solution {
public:
    int memoisation(int idx, int buy, int fee, vector<int>& prices, vector<vector<int>> &dp)
    {
        if(idx >= prices.size())
            return 0;
        if(dp[idx][buy] != -1)
            return dp[idx][buy];
        
        int profit;
        if(buy)
        {
            int buyIt = -prices[idx] + memoisation(idx+1, 0, fee, prices, dp);
            int notBuyIt = memoisation(idx+1, 1, fee, prices, dp);
            profit = max(buyIt, notBuyIt);
        }
        else
        {
            int sellIt = prices[idx] + memoisation(idx+1, 1, fee, prices, dp) - fee;
            int notSellIt = memoisation(idx+1, 0, fee, prices, dp);
            profit = max(sellIt, notSellIt);
        }
        dp[idx][buy] = profit;
        return dp[idx][buy];
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return memoisation(0, 1, fee, prices, dp);        
    }
};