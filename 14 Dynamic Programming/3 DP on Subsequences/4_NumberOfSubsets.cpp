#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int N = 1000000007;
    int memoisation(int arr[], int idx, int sum, vector<vector<int>> &dp)
    {
        if (idx == 0)
        {
            if (sum == 0)
            {
                if (arr[0] == 0)
                    return 2;
                else
                    return 1;
            }
            return arr[0] == sum ? 1 : 0;
        }
        if (dp[idx][sum] != -1)
            return dp[idx][sum];
        int nottake = memoisation(arr, idx - 1, sum, dp) % N;
        int take = 0;
        if (sum >= arr[idx])
            take = memoisation(arr, idx - 1, sum - arr[idx], dp) % N;
        dp[idx][sum] = (take + nottake) % N;
        return dp[idx][sum];
    }

    int tabulation(int n, int sum, int arr[])
    {
        int dp[n][sum+1] = {-1};
        if(arr[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;

        if(arr[0] != 0)
            dp[0][arr[0]] = 1;
            
        for(int i = 1; i < n; i++)
        {
            for(int j = 0; j <= sum; j++)
            {
                int notpick = dp[i-1][j] % N;
                int pick = 0;
                if(j-arr[i] >= 0)
                    pick = dp[i-1][j-arr[i]] % N;
                dp[i][j] = (pick + notpick) % N;
            }
        }
        return dp[n-1][sum];
    }
    int perfectSum(int arr[], int n, int sum)
    {
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
        // int ans = memoisation(arr, n - 1, sum, dp);
        int ans = tabulation(n, sum, arr);
        return ans;
    }
};