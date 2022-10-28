#include<bits/stdc++.h>
using namespace std;

int memoisation(int day, int task, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if(day == 0)
        return points[day][task];
    
    if(dp[day][task] != -1)
        return dp[day][task];
    for(int i = 0; i<3; i++)
    {
        if(i != task)
            dp[day][task] = max(dp[day][task], memoisation(day-1, i, points, dp) + points[day][task]);
    }       
    return dp[day][task];
}

int tabulation(int day, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    dp[0][0] = points[0][0];
    dp[0][1] = points[0][1];
    dp[0][2] = points[0][2];
    
    for(int i = 1; i <= day; i++)
    {
        for( int task = 0; task<3; task++)
        {
            if(task == 0)
              dp[i][task] = points[i][task] + max(dp[i-1][1], dp[i-1][2]);
            if(task == 1)
              dp[i][task] = points[i][task] + max(dp[i-1][0], dp[i-1][2]);
            if(task == 2)
              dp[i][task] = points[i][task] + max(dp[i-1][0], dp[i-1][1]);
        }
    }
    return max(dp[day][0], max(dp[day][1], dp[day][2]));
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(3, -1));
    int ans = max(memoisation(n-1, 0, points, dp), max(memoisation(n-1, 1, points, dp), memoisation(n-1, 2, points, dp)));
    return ans;
    return tabulation(n-1, points, dp);
}