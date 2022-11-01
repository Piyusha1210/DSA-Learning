#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int memoisation(int idx, int amount, vector<int>& coins, vector<vector<int>> &dp)
    {
        if(amount == 0)
            return 0;
        if(idx < 0)
        {
            if(amount > 0)
                return INT_MAX;
            return 0;
        }
        
        if(dp[idx][amount] != -1)
            return dp[idx][amount];
        
        int notpick = memoisation(idx-1, amount, coins, dp);
        int pick = INT_MAX;
        if(coins[idx] <= amount)
        {
            pick = memoisation(idx, amount-coins[idx], coins, dp);
            if(pick != INT_MAX)
                pick += 1;            
        }
        
        dp[idx][amount] = min(pick, notpick);
        return dp[idx][amount];
    }
    
    int tabulation(vector<int>& coins, int amount)
    {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, INT_MAX));
        dp[0][0] = 0;
        for(int i = 1; i <= amount; i++)
        {
            if(i-coins[0] >= 0 && dp[0][i-coins[0]] != INT_MAX)
                dp[0][i] = dp[0][i-coins[0]] + 1;
        }
        
        for(int idx = 1; idx<n; idx++)
        {
            for(int val = 0; val <= amount; val++)
            {
                int notpick = dp[idx-1][val];
                int pick = INT_MAX;
                if(val - coins[idx] >= 0 && dp[idx][val-coins[idx]] != INT_MAX)
                {
                    pick = dp[idx][val-coins[idx]];
                    if(pick != INT_MAX)
                        pick += 1;            
                }
                dp[idx][val] = min(pick, notpick);
            }
        }
        return dp[n-1][amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        // int ans = memoisation(n-1, amount, coins, dp);
        int ans = tabulation(coins, amount);
        if(ans == INT_MAX)
            ans = -1;
        return ans;
    }
};