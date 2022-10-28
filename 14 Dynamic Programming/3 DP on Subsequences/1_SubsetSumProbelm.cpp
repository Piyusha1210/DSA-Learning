#include<bits/stdc++.h>
using namespace std;

class Solution{   
public:
    bool memoisation(int idx, int sum, vector<int> arr, vector<vector<int>> &dp)
    {
        if(idx < 0)
            return false;
            
        if(arr[idx] == sum)
            return true;
        if(dp[idx][sum] != -1)
            return dp[idx][sum];
            
        bool nottake = memoisation(idx-1, sum, arr, dp);
        bool take = false;
        if(arr[idx] < sum)
            take = memoisation(idx-1, sum - arr[idx], arr, dp);
        
        if(take || nottake)
            dp[idx][sum] = 1;
        else
            dp[idx][sum] = 0;
        return dp[idx][sum];
    }
    
    bool tabulation(int sum, vector<int> arr)
    {
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
        for(int i = 0; i<n; i++)
        {
            dp[i][0] = true;
        }
        dp[0][arr[0]] = true;
        
        for(int i = 1; i<n; i++)
        {
            for(int j = 1; j <= sum; j++)
            {
                bool nottake = dp[i-1][j];
                bool take = false;
                if(arr[i] <= j)
                    take = dp[i-1][j - arr[i]];
                
                dp[i][j] = take || nottake;
            }
        }
        return dp[n-1][sum];
    }
    
    bool isSubsetSum(vector<int>arr, int sum){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        // return memoisation(n-1, sum, arr, dp);
        return tabulation(sum, arr);
    }
};