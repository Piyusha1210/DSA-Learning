#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int memoisation(int idx, int amount, vector<int>& coins, vector<vector<int>> &dp)
    {
        if(amount == 0)
            return 1;
        
        if(idx < 0)
            return 0;
        
        if(dp[idx][amount] != -1)
            return dp[idx][amount];
        
        int notpick = memoisation(idx-1, amount, coins, dp);
        int pick = 0;
        if(amount >= coins[idx])
        {
            pick = memoisation(idx, amount - coins[idx], coins, dp);
        }
        dp[idx][amount] = pick + notpick;
        return dp[idx][amount];
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return memoisation(n-1, amount, coins, dp);        
    }
};