#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h> 
int N  = 1000000007;
int memoisation(int n, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if(n == 0)
    {
        if(target == 0)
        {
            if(arr[0] == 0)
                return 2;
            else
                return 1;
        }
        return arr[0] == target ? 1 : 0;
    }
    if(dp[n][target] != -1)
        return dp[n][target];
    
    int notpick = memoisation(n-1, target, arr, dp) % N;
    int pick = 0;
    if(arr[n] <= target)
    {
        pick = memoisation(n-1, target-arr[n], arr, dp) % N;
    }
    dp[n][target] = (pick + notpick) % N;
    return dp[n][target];
}
int countPartitions(int n, int d, vector<int> &arr) {
    int sum = 0;
    for(int i = 0; i<n; i++)
    {
        sum += arr[i];
    }
    /*
        s1 - s2 = d;
        sum - s2 - s2 = d;
        sum - d = 2 * s2;
        s2 = (sum - d) / 2;
    */
    if(sum - d < 0 || (sum - d) % 2 != 0)
        return 0;
    int target = (sum - d) / 2;
    
//     cout<< target <<" ";
    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    return memoisation(n-1, target, arr, dp);
}