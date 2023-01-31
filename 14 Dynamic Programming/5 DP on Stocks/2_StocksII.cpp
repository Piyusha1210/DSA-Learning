#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
class Solution {
public:
    int memoisation(int idx, int buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if(idx == prices.size())
            return 0;

        if(dp[idx][buy] != -1)
            return dp[idx][buy];
        
        int profit;

        if(buy == 0)
        {
            /* If we have to buy now */
            int buyit = -prices[idx] + memoisation(idx+1, 1, prices, dp);
            int notbuyit = memoisation(idx+1, 0, prices, dp);
            profit = max(buyit, notbuyit);
        }
        else
        {
            /* else if we have to sell now */
            int sellit = prices[idx] + memoisation(idx+1, 0, prices, dp);
            int notsellit = memoisation(idx+1, 1, prices, dp);
            profit = max(sellit, notsellit);
        }
        dp[idx][buy] = profit;
        return dp[idx][buy];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        /* 2d DP where row->point to index & col->point to whether to buy it or sell it
        buy = 0 -> we have to buy;
        buy = 1 -> we have to sell it
        */
        return memoisation(0, 0, prices, dp);
    }
};